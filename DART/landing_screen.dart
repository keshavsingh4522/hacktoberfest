import 'package:flutter/material.dart';

class LandingPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Column(
        children: [
          Expanded(child: _LandingBanner()),
          Container(
            width: 250,
            child: MaterialButton(
              height: 50,
              color: Colors.red,
              shape: RoundedRectangleBorder(
                borderRadius: BorderRadius.circular(60),
              ),
              onPressed: () {
                Get.to(LoginPage());
              },
              child: Text('Login'),
            ),
          ),
          SizedBox(height: 40),
        ],
      ),
    );
  }
}

class _LandingBanner extends StatefulWidget {
  @override
  __LandingBannerState createState() => __LandingBannerState();
}

class __LandingBannerState extends State<_LandingBanner> {
  List<Map> images = [
    {
      'image':
          'https://image.freepik.com/free-vector/focused-tiny-people-reading-books_74855-5836.jpg',
      'title': 'Find best deal',
      'message':
          'Find deals for any season from cosy country homes to city flats'
    },
    {
      'image':
          'https://image.freepik.com/free-vector/happy-diverse-students-celebrating-graduation-from-school_74855-5853.jpg',
      'title': 'Find best deal 2',
      'message':
          'Find deals for any season from cosy country homes to city flats'
    },
  ];
  PageController _pageController = PageController();
  double currentPage = 0;

  @override
  void initState() {
    _pageController.addListener(() {
      setState(() {
        currentPage = _pageController.page!;
      });
    });
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return Column(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        Container(
          width: double.infinity,
          height: 400,
          child: PageView.builder(
            controller: _pageController,
            itemCount: images.length,
            itemBuilder: (context, index) {
              var d = images[index];
              return Column(
                children: [
                  Image.network(d['image'], width: 300, height: 300),
                  Text(
                    d['title'],
                  ),
                  SizedBox(height: 10),
                  Container(
                    width: 250,
                    child: Text(
                      d['message'],
                      textAlign: TextAlign.center,
                    ),
                  ),
                ],
              );
            },
          ),
        ),
        SizedBox(
          height: 40,
        ),
        Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: _buildPageIndicator(),
        ),
      ],
    );
  }

  List<Widget> _buildPageIndicator() {
    List<Widget> list = [];
    for (int i = 0; i < images.length; i++) {
      list.add(i == currentPage ? _indicator(true) : _indicator(false));
    }
    return list;
  }

  Widget _indicator(bool isActive) {
    return Container(
      height: 10,
      child: AnimatedContainer(
        duration: Duration(milliseconds: 50),
        margin: EdgeInsets.symmetric(horizontal: 4.0),
        height: isActive ? 10 : 8.0,
        width: isActive ? 12 : 8.0,
        decoration: BoxDecoration(
          shape: BoxShape.circle,
          color: isActive ? Colors.red : Color(0XFFEAEAEA),
        ),
      ),
    );
  }
}
