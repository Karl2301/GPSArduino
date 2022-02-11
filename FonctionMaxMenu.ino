void rafmenu() {
  if (menuselector == 0) {
    if (menu > MaxMenu) {
      menu = MaxMenu;
    } else if (menu < 1) {
      menu = 1;
    }
    if (menu == 1) {
      menuSelct1();
    } else if (menu == 2) {
      menuSelct2();
    } else if (menu == 3) {
      menuSelct3();
    } else if (menu == 4) {
      menuSelct4();
    } else if (menu == 5) {
      menuSelct5();
    } else if (menu == 6) {
      menuSelct6();
    } else if (menu == 7) {
      menuSelct7();
    } else if (menu == 8) {
      menuSelct8();
    }else if (menu == 9) {
      menuSelct9();
    }else if (menu == 10) {
      menuSelct10();
    }else if (menu == 11) {
      menuSelct11();
    }else if (menu == 12) {
      menuSelct12();
    }
  }
}
