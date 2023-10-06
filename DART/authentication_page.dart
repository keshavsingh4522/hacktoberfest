import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(const Authpage());
}

class Authpage extends StatefulWidget {
  const Authpage({
    Key? key,
  }) : super(key: key);

  @override
  State<Authpage> createState() => _AuthpageState();
}

class _AuthpageState extends State<Authpage> {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Page(),
    );
  }
}

class Page extends StatefulWidget {
  const Page({Key? key}) : super(key: key);

  @override
  State<Page> createState() => _PageState();
}

class _PageState extends State<Page> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      resizeToAvoidBottomInset: false,
      backgroundColor: Color(0xfff665BE9),
      body: Column(
        mainAxisAlignment: MainAxisAlignment.spaceEvenly,
        children: [
          Image.asset(
            'assets/images/logo.png',
            width: 100,
            height: 100,
          ),
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              Padding(
                padding: const EdgeInsets.all(0.0),
                child: Image.asset(
                  'assets/images/Movie.png',
                ),
              ),
              Image.asset(
                'assets/images/Time.png',
              ),
            ],
          ),
          const Text(
            'Book tickets for all your',
            style: TextStyle(
              color: Colors.white,
              fontSize: 24,
            ),
          ),
          const Text(
            'favourite movies',
            style: TextStyle(
              color: Colors.white,
              fontSize: 24,
            ),
          ),
          const Padding(
            padding: const EdgeInsets.only(right: 260.0),
            child: Text(
              'Username',
              textAlign: TextAlign.left,
              style: TextStyle(
                color: Colors.white,
                fontSize: 20,
              ),
            ),
          ),
          Padding(
            padding: const EdgeInsets.all(10.0),
            child: Container(
              height: 45,
              width: 350,
              child: const TextField(
                decoration: InputDecoration(
                  filled: true,
                  fillColor: Color(0xfffD9D9D9),
                  border: OutlineInputBorder(),
                  labelText: 'User Name',
                ),
              ),
            ),
          ),
          const Padding(
            padding: const EdgeInsets.only(right: 260.0),
            child: Text(
              'Password',
              textAlign: TextAlign.left,
              style: TextStyle(
                color: Colors.white,
                fontSize: 20,
              ),
            ),
          ),
          Padding(
            padding: const EdgeInsets.all(10.0),
            child: Container(
              height: 45,
              width: 350,
              child: const TextField(
                decoration: InputDecoration(
                  filled: true,
                  fillColor: Color(0xfffD9D9D9),
                  border: OutlineInputBorder(),
                  labelText: 'Password',
                ),
              ),
            ),
          ),
          Container(
            width: 95,
            child: ElevatedButton(
              style: ButtonStyle(
                shape: MaterialStateProperty.all<RoundedRectangleBorder>(
                  RoundedRectangleBorder(
                    borderRadius: BorderRadius.circular(16.0),
                  ),
                ),
              ),
              onPressed: () {},
              child: const Text(
                'Login',
              ),
            ),
          ),
          const Text(
            'Sign in with',
            style: TextStyle(
              letterSpacing: 2.0,
              color: Colors.white,
              fontSize: 20,
            ),
          ),
          IconButton(
            onPressed: () {},
            icon: Image.asset('assets/images/g.png'),
          ),
          const SizedBox(
            height: 20.0,
          ),
        ],
      ),
    );
  }
}
