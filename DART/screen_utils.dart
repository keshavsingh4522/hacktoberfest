/*
 Written by: BAIMAM BOUKAR JEAN JACQUES
 Email: baimamboukar@gmail.com
 
 THIS PROGRAMM IS A SET OF UTILS TO GET THE CURRENT CONTEXT'S SCREEN SIZE, ORIENTATION, SCREEN TYPE (Mobile, Web, Tablet) 

*/


import 'package:flutter/material.dart';

class Screen {
  /*
          -------------------DEVICE SIZE-----------------------
        ♦ height(context): returns the height of the device
        ♦ width(context): returns the width of the device
   */
  static double height(context) => MediaQuery.of(context).size.height;
  static double width(context) => MediaQuery.of(context).size.width;

  /*
          --------------------DEVICE TYPE---------------------
        ♦ isMobile(context): returns true is the device is mobile phone
        ♦ isTblet(context): returns true if the device is tablet
        ♦ isDesktop(context): returns true if the device is desktop
        ♦ watch(context): returns true if the device is large
   */
  static bool isMobile(context) => MediaQuery.of(context).size.width <= 480.0;
  static bool isTblet(context) =>
      MediaQuery.of(context).size.width > 480 &&
      MediaQuery.of(context).size.width <= 768.0;
  static bool isDesktop(context) =>
      MediaQuery.of(context).size.width > 768 &&
      MediaQuery.of(context).size.width <= 1024.0;
  static bool watch(context) => MediaQuery.of(context).size.width > 1024.0;

  /*
          --------------------DEVICE ORIENTATION-----------------------
        ♦ orientation(context): returns the orientation of the device(landscape or portrait)
        ♦ isLandscape(context): returns true if the device is in landscape mode
        ♦ isPortait(context): returns true if the device is in portrait mode
   */
  static Orientation orientation(context) => MediaQuery.of(context).orientation;
  static bool isLandscape(context) =>
      MediaQuery.of(context).orientation == Orientation.landscape;
  static bool isPortrait(context) =>
      MediaQuery.of(context).orientation == Orientation.portrait;
}
