#include "MenuShell.h"
#include "TabbedArea.h"
#include "guichan.hpp"
#include "GraphicsUtil.h"
#include "PlayerData.h"
#include "ListBox.h"
#include "StringListModel.h"
#include "MenuAction.h"
#include "MenuPane.h"
#include "TabChangeListener.h"

#include "DebugUtils.h"

const int debugFlag = DEBUG_MENU;

MenuShell::MenuShell(PlayerData& playerData)
{
   try
   {
      setWidth(GraphicsUtil::getInstance()->getWidth());
      setHeight(GraphicsUtil::getInstance()->getHeight());

      const gcn::Color menuBackgroundColor(50, 50, 50, 150);
      const gcn::Rectangle menuAreaRect(0, 0, getWidth() * 0.8 - 5, getHeight() - 10);

      bg = new gcn::Icon("data/images/menubg.jpg");

      menuTabs = new edwt::TabbedArea();
      menuArea = new edwt::Container();
      menuArea->setDimension(menuAreaRect);
      menuArea->setOpaque(false);

      menuTabs->setDimension(menuAreaRect);
      menuTabs->setForegroundColor(0xFFFFFF);
      menuTabs->setBaseColor(menuBackgroundColor);
      menuTabs->setDimension(menuAreaRect);

      menuTabs->addTab("Party", menuArea);

      CharacterList party = playerData.getParty();
      for (CharacterList::iterator iter = party.begin(); iter != party.end(); ++iter)
      {
         menuTabs->addTab(iter->first, menuArea);
      }

      populateOpsList();
      actionsListBox = new edwt::ListBox(listOps);
      actionsListBox->adjustSize();
      actionsListBox->setWidth((getWidth() * 0.2) - 10);
      actionsListBox->setBackgroundColor(menuBackgroundColor);
      actionsListBox->setOpaque(true);
      actionsListBox->setRowPadding(5);

      add(bg);
      add(menuTabs, getWidth() * 0.2, 5);
      add(actionsListBox, 5, menuTabs->getTabHeight() + 5);
   }
   catch (gcn::Exception e)
   {
      DEBUG(e.getMessage());
   }
}

void MenuShell::populateOpsList()
{
   listOps = new edwt::StringListModel();

   listOps->add("Items", ITEM_PANEL);
   listOps->add("Equip", EQUIP_PANEL);
   listOps->add("Status", STATUS_PANEL);
   listOps->add("Skills", SKILLS_PANEL);
   listOps->add("Formation", FORMATION_PANEL);
   listOps->add("Party Change", PARTY_CHANGE_PANEL);
   listOps->add("Options", OPTIONS_PANEL);
   listOps->add("Data", DATA_PANEL);
}

void MenuShell::addPane(MenuPane* menuPane)
{
   menuArea->add(menuPane);
}

void MenuShell::removePane(MenuPane* menuPane)
{
   menuArea->remove(menuPane);
}

void MenuShell::setTabChangeListener(edwt::TabChangeListener* listener)
{
   menuTabs->setTabChangeListener(listener);
}

MenuShell::~MenuShell()
{
   delete menuArea;
   delete menuTabs;
	delete listOps;
	delete actionsListBox;
   delete bg;
}