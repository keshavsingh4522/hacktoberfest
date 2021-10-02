import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'My Info',
      theme: ThemeData(
        primarySwatch: Colors.yellow,
      ),
      home: HomePage(),
    );
  }
}

class HomePage extends StatelessWidget {
  const HomePage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Ravi-lk'),
      ),
      body: Column(
        children: [
          SizedBox(
            height: 30,
          ),
          Image.network(
              'https://user-images.githubusercontent.com/60037870/124356761-78067a80-dc35-11eb-9f9a-8971f1849943.png', width: double.infinity,),
          SizedBox(
            height: 30,
          ),
          Text(
            'Ravindu Lakmina',
            style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
          ),
            SizedBox(
            height: 30,
          ),
          Text(
            'I\'m doing mobile apps with Flutter',
            style: TextStyle(fontSize: 15, fontWeight: FontWeight.bold),
          ),
          SizedBox(
            height: 30,
          ),
          Row(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Image.network(
                  'https://www.iconpacks.net/icons/1/free-mail-icon-142-thumb.png', width: 50,),
                  SizedBox(width: 15),
              Text('Ravindu.lakmina1@gmail.com'),
              
              
            ],
          ),
          Row(
              mainAxisAlignment: MainAxisAlignment.center,
             
            children: [
               Image.network(
                  'https://static-00.iconduck.com/assets.00/github-icon-512x512-61im4xuw.png', width: 50,),
               SizedBox(width: 15),
              Text('https://github.com/Ravi-lk')
            ],
          )
        ],
      ),
    );
  }
}
