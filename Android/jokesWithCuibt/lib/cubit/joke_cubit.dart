import 'package:bloc/bloc.dart';
import 'package:equatable/equatable.dart';
import 'package:meta/meta.dart';
import 'package:random_jokes/data/joke_service.dart';
import 'package:random_jokes/data/model/jokes.dart';
part 'joke_state.dart';

class JokeCubit extends Cubit<JokeState> {
  JokeCubit() : super(JokeInitial()) {
    emit(JokeInitial());
    emit(JokeLoading());
    getJoke();
  }
  getJoke() async {
    try {
      Joke joke = await JokeService().getJoke();
      if (joke != null) {
        emit(JokeLoaded(joke: joke));
      }
    } catch (e) {
      emit(JokeError(errorMessage: "Network error please check your internet connection"));
    }
  }
}
