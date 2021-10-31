import 'dart:convert';
import 'package:http/http.dart' as http;
import 'package:random_jokes/data/model/jokes.dart';

abstract class JokeRepository {
  Future<Joke> getJoke();
}

class JokeService implements JokeRepository {
  static const String URL = 'https://official-joke-api.appspot.com/random_joke';
  @override
  Future<Joke> getJoke()  {
    return http.get(Uri.parse(URL.toString())).then((data) {
      final jsonData = json.decode(data.body);
      return Joke.formJson(jsonData);
    });
  }
}
