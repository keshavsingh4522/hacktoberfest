import 'dart:math';

import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/physics.dart';
import 'package:zflutter/zflutter.dart';

class Dices extends StatefulWidget {
  _PhysicsAnimation createState() => _DicesState();
}

class _DicesState extends State<Dices>
    with SingleTickerProviderStateMixin {
  AnimationController animationController;

  SpringSimulation simulation;
  int num = 1;
  int num2 = 1;
  ZVector rotation = ZVector.zero;
  double zRotation = 0;

  @override
  void initState() {
    super.initState();

    simulation = SpringSimulation(
      SpringDescription(
        mass: 1,
        stiffness: 20,
        damping: 2,
      ),
      1, // starting point
      0, // ending point
      1, // velocity
    );

    animationController =
        AnimationController(vsync: this, duration: Duration(milliseconds: 2000))
          ..addListener(() {
            // rotation = rotation + ZVector.all(0.1);
            setState(() {});
          });
  }

  void random() {
    zRotation = Random().nextDouble() * tau;
    num = Random().nextInt(5) + 1;
    num2 = 6 - Random().nextInt(5);
  }

  @override
  Widget build(BuildContext context) {
    final curvedValue = CurvedAnimation(
      curve: Curves.ease,
      parent: animationController,
    );
    final firstHalf = CurvedAnimation(
      curve: Interval(0, 1),
      parent: animationController,
    );
    final secondHalf = CurvedAnimation(
      curve: Interval(0, 0.3),
      parent: animationController,
    );

    final zoom = (simulation.x(animationController.value)).abs() / 2 + 0.5;

    return GestureDetector(
      onTap: () {
        if (animationController.isAnimating)
          animationController.reset();
        else {
          animationController.forward(from: 0);
          random();
        }
      },
      child: Container(
        color: Colors.transparent,
        child: ZIllustration(
          zoom: 1.5,
          children: [
            ZPositioned(
              translate: ZVector.only(x: 100 * zoom),
              child: ZGroup(
                children: [
                  ZPositioned(
                    scale: ZVector.all(zoom),
                    rotate:
                        getRotation(num2).multiplyScalar(curvedValue.value) -
                            ZVector.all((tau / 2) * (firstHalf.value)) -
                            ZVector.all((tau / 2) * (secondHalf.value)),
                    child: ZPositioned(
                        rotate: ZVector.only(
                            z: -zRotation * 1.9 * (animationController.value)),
                        child: Dice(
                          zoom: zoom,
                          color: Colors.green,
                        )),
                  ),
                ],
              ),
            ),
            ZPositioned(
              translate: ZVector.only(x: -100 * zoom),
              child: ZGroup(
                children: [
                  ZPositioned(
                    scale: ZVector.all(zoom),
                    rotate: getRotation(num).multiplyScalar(curvedValue.value) -
                        ZVector.all((tau / 2) * (firstHalf.value)) -
                        ZVector.all((tau / 2) * (secondHalf.value)),
                    child: ZPositioned(
                        rotate: ZVector.only(
                            z: -zRotation * 2.1 * (animationController.value)),
                        child: Dice(zoom: zoom)),
                  ),
                ],
              ),
            ),
          ],
        ),
      ),
    );
  }

  @override
  void dispose() {
    animationController.dispose();
    super.dispose();
  }
}

ZVector getRotation(int num) {
  switch (num) {
    case 1:
      return ZVector.zero;
    case 2:
      return ZVector.only(x: tau / 4);
    case 3:
      return ZVector.only(y: tau / 4);
    case 4:
      return ZVector.only(y: 3 * tau / 4);
    case 5:
      return ZVector.only(x: 3 * tau / 4);
    case 6:
      return ZVector.only(y: tau / 2);
  }
  throw ('num $num is not in the dice');
}

class Face extends StatelessWidget {
  final double zoom;
  final Color color;

  const Face({Key key, this.zoom = 1, this.color}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return ZRect(
      stroke: 50 * zoom,
      width: 50,
      height: 50,
      color: color,
    );
  }
}

class Dot extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return ZCircle(
      diameter: 15,
      stroke: 0,
      fill: true,
      color: Colors.white,
    );
  }
}

class GroupTwo extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return ZGroup(
      sortMode: SortMode.update,
      children: [
        ZPositioned(translate: ZVector.only(y: -20), child: Dot()),
        ZPositioned(translate: ZVector.only(y: 20), child: Dot()),
      ],
    );
  }
}

class GroupFour extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return ZGroup(
      sortMode: SortMode.update,
      children: [
        ZPositioned(translate: ZVector.only(x: 20, y: 0), child: GroupTwo()),
        ZPositioned(translate: ZVector.only(x: -20, y: 0), child: GroupTwo()),
      ],
    );
  }
}

class Dice extends StatelessWidget {
  final Color color;
  final double zoom;

  const Dice({Key key, this.zoom = 1, this.color = const Color(0xffF23726)})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    return ZGroup(
      children: [
        ZGroup(
          sortMode: SortMode.update,
          children: [
            ZPositioned(
                translate: ZVector.only(z: -25),
                child: Face(zoom: zoom, color: color)),
            ZPositioned(
                translate: ZVector.only(z: 25),
                child: Face(zoom: zoom, color: color)),
            ZPositioned(
                translate: ZVector.only(y: 25),
                rotate: ZVector.only(x: tau / 4),
                child: Face(
                  zoom: zoom,
                  color: color,
                )),
            ZPositioned(
                translate: ZVector.only(y: -25),
                rotate: ZVector.only(x: tau / 4),
                child: Face(zoom: zoom, color: color)),
          ],
        ),
        //one
        ZPositioned(translate: ZVector.only(z: 50), child: Dot()),
        //two
        ZPositioned(
          rotate: ZVector.only(x: tau / 4),
          translate: ZVector.only(y: 50),
          child: ZGroup(
            sortMode: SortMode.update,
            children: [
              ZPositioned(translate: ZVector.only(y: -20), child: Dot()),
              ZPositioned(translate: ZVector.only(y: 20), child: Dot()),
            ],
          ),
        ),
        //three
        ZPositioned(
          rotate: ZVector.only(y: tau / 4),
          translate: ZVector.only(x: 50),
          child: ZGroup(
            sortMode: SortMode.update,
            children: [
              Dot(),
              ZPositioned(translate: ZVector.only(x: 20, y: -20), child: Dot()),
              ZPositioned(translate: ZVector.only(x: -20, y: 20), child: Dot()),
            ],
          ),
        ),
        //four
        ZPositioned(
          rotate: ZVector.only(y: tau / 4),
          translate: ZVector.only(x: -50),
          child: ZGroup(
            sortMode: SortMode.update,
            children: [
              ZPositioned(
                  translate: ZVector.only(x: 20, y: 0), child: GroupTwo()),
              ZPositioned(
                  translate: ZVector.only(x: -20, y: 0), child: GroupTwo()),
            ],
          ),
        ),

        //five
        ZPositioned(
          rotate: ZVector.only(x: tau / 4),
          translate: ZVector.only(y: -50),
          child: ZGroup(
            sortMode: SortMode.update,
            children: [
              Dot(),
              ZPositioned(child: GroupFour()),
            ],
          ),
        ),

        //six
        ZPositioned(
          translate: ZVector.only(z: -50),
          child: ZGroup(
            sortMode: SortMode.update,
            children: [
              ZPositioned(rotate: ZVector.only(z: tau / 4), child: GroupTwo()),
              ZPositioned(child: GroupFour()),
            ],
          ),
        ),
      ],
    );
  }
}