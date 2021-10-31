import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:random_jokes/theme/app_theme.dart';
import 'Presentation/jokeScreen/ShowJokes.dart';
import 'package:random_jokes/cubit/joke_cubit.dart';

void main() {
  runApp(RandomJokes());
}

class RandomJokes extends StatefulWidget {
  @override
  _RandomJokesState createState() => _RandomJokesState();
}

class _RandomJokesState extends State<RandomJokes> {
  @override
  Widget build(BuildContext context) {
    return BlocProvider(
      create: (_) => JokeCubit(),
      child: MaterialApp(
        theme: AppTheme.lightTheme,
        darkTheme: AppTheme.darkTheme,
        themeMode: ThemeMode.system,
        title: 'Joke',
        home: ShowJokes(),
        debugShowCheckedModeBanner: false,
      ),
    );
  }
}
