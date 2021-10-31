part of 'joke_cubit.dart';

@immutable
abstract class JokeState extends Equatable {}

class JokeInitial extends JokeState {
  @override
  List<Object> get props => [];
}
class JokeLoading extends JokeState {
  @override
  List<Object> get props => [];
}
class JokeLoaded extends JokeState {
  final Joke joke;
  JokeLoaded({@required this.joke});
  @override
  List<Object> get props => [joke];
}
class JokeError extends JokeState {
  final String errorMessage;

  JokeError({@required this.errorMessage});
  @override
  List<Object> get props => [errorMessage];
}
