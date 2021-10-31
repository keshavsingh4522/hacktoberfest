import 'package:equatable/equatable.dart';
import 'package:meta/meta.dart';

class Joke extends Equatable {
  final int id;
  final String type;
  final String setup;
  final String punchline;

  Joke(
      {@required this.id,
      @required this.type,
      @required this.setup,
      @required this.punchline});

  @override
  List<Object> get props => [
        id,
        type,
        setup,
        punchline,
      ];

  factory Joke.formJson(Map<String, dynamic> item) {
    return Joke(
      id: item['id'],
      type: item['type'],
      setup: item['setup'],
      punchline: item['punchline'],
    );
  }
}
