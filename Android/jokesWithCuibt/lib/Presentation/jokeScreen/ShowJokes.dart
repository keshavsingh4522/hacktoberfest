import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:random_jokes/data/model/jokes.dart';
import '../../cubit/joke_cubit.dart';

class ShowJokes extends StatefulWidget {
  @override
  State<ShowJokes> createState() => _ShowJokesState();
}

class _ShowJokesState extends State<ShowJokes> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        leading: Padding(
          padding: const EdgeInsets.only(left: 10.0),
          child: Image.asset('assets/images/logo.png'),
        ),
        centerTitle: true,
        title: Text("Jokes"),
      ),
      body: Container(
        alignment: Alignment.center,
        child: BlocListener<JokeCubit, JokeState>(
          listener: (context, state) {
            if (state is JokeError) {
              ScaffoldMessenger.of(context).showSnackBar(SnackBar(content: Text(state.errorMessage)));

            }
          },
          child: BlocBuilder<JokeCubit, JokeState>(
            builder: (context, state) {
              if (state is JokeInitial) {
                return buildInitialInput();
              } else if (state is JokeLoading) {
                return buildLoading(context: context);
              } else if (state is JokeLoaded) {
                return buildColumnWithData(context:context, joke:state.joke);
              } else if (state is JokeError) {
                return buildError(error: state.errorMessage,context: context);
              } else {
                return Container();
              }
            },
          ),
        ),
      ),
    );
  }
}

Widget buildError({@required String error,@required BuildContext context}) {
  return Padding(
    padding: const EdgeInsets.only(left: 20.0, right: 20.0),
    child: Column(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
     Text(
          error,
          style: TextStyle(
            fontSize: 20,
            fontWeight: FontWeight.w700,
          ),
        ),
        SizedBox(height: 30,),
        reloadButton(context),
      ],
    ),
  );
}

Widget buildColumnWithData({@required BuildContext context,@required Joke joke}) {
  return Column(
    mainAxisAlignment: MainAxisAlignment.spaceEvenly,
    crossAxisAlignment: CrossAxisAlignment.center,
    children: <Widget>[
      Padding(
        padding: const EdgeInsets.only(left: 20.0, right: 20.0),
        child: Center(
          child: Text(
            joke.setup,
            style: TextStyle(
              fontSize: 20,
              fontWeight: FontWeight.w700,
            ),
          ),
        ),
      ),
      Divider(
        color: Theme.of(context).accentColor,
        height: 20,
        thickness: 2,
      ),
      FutureBuilder(
        future: fetchData(joke.punchline),
        builder: (BuildContext context, AsyncSnapshot<String> snapshot) {
          if (snapshot.connectionState == ConnectionState.waiting) {
            return Container(
              child: Text(" "),
            );
          } else if (snapshot.connectionState == ConnectionState.done) {
            if (snapshot.data != null) {
              return Padding(
                padding: const EdgeInsets.only(left: 20.0, right: 20.0),
                child: Center(
                  child: Text(
                    snapshot.data,
                    style: TextStyle(
                      fontSize: 30,
                      fontWeight: FontWeight.w100,
                    ),
                  ),
                ),
              );
            } else {
              return Container();
            }
          } else {
            return Container();
          }
        },
      ),
      reloadButton(context),
    ],
  );
}

Widget buildLoading({@required BuildContext context}) {
  return Center(
    child: CircularProgressIndicator(color: Theme.of(context).canvasColor),
  );
}

Widget buildInitialInput() {
  return Container();
}

Future<String> fetchData(punchline) async {
  await Future.delayed(Duration(seconds: 2));
  return punchline;
}

Widget reloadButton(BuildContext context) {
  return FloatingActionButton.extended(
    backgroundColor: Theme.of(context).accentColor,
    onPressed: () {
      BlocProvider.of<JokeCubit>(context).getJoke();
    },
    label: Text("new Joke"),
  );
}
