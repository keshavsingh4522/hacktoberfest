// kunaljainwi/FlutterFirebaseDesigns

late TabController _tabController;


@override
  void initState() {
    super.initState();

    _tabController = TabController(length: 7, vsync: this);
  }
@override
  void dispose() {
    _tabController.dispose();

    super.dispose();
  }

SliverAppBar(
              elevation: 7,
              
              floating: true,
              pinned: true,

              // shape: RoundedRectangleBorder(
              //     borderRadius: BorderRadius.only(
              //         bottomLeft: Radius.circular(20),
              //         bottomRight: Radius.circular(20))),
              // backgroundColor: Colors.orange,
              //leadingWidth: 50.0,
              centerTitle: true,
              title: SizedBox(
                height: 100,
                width: 200,
                child: Image.asset("assets/images/9.png",
                    filterQuality: FilterQuality.low, fit: BoxFit.cover),
              ),

              bottom: TabBar(
                onTap: (value) {
                  showPosType = value == 0
                      ? "music"
                      : value == 1
                          ? "poem"
                          : value == 2
                              ? "lyrics"
                              : value == 3
                                  ? "story"
                                  : value == 4
                                      ? "painting"
                                      : value == 5
                                          ? "sclupture"
                                          : value == 6
                                              ? "digitalart"
                                              : "";
                },
                indicatorSize: TabBarIndicatorSize.tab,
                indicator: UnderlineTabIndicator(
                    borderSide: BorderSide(
                        // color: Colors.white,
                        width: 3)),

                indicatorPadding:
                    EdgeInsets.only(bottom: 10, left: 10, right: 10),
                // indicator: BoxDecoration(
                //     //borderRadius: BorderRadius.circular(50), // Creates border

                //     shape: BoxShape.rectangle,
                //     color: Colors.black26),
                isScrollable: true,
                controller: _tabController,
                tabs: [
                  Tab(
                    text: "Music",
                    icon: Icon(EvaIcons.music),
                  ),
                  Tab(
                    text: "Poem",
                    icon: Icon(Icons.microwave),
                  ),
                  Tab(
                    text: "Lyrics",
                    icon: Icon(Icons.library_music_sharp),
                  ),
                  Tab(text: "Story"),
                  Tab(text: "Painting"),
                  Tab(text: "Sclupture"),
                  Tab(
                    text: "Digital Art",
                  )
                ],
              ),

              //forceElevated: true,
              //automaticallyImplyLeading: false,
              //
              actions: <Widget>[
                // CircularButton(
                //     icon: Icon(Icons.notifications_none),
                //     onPressed: () {
                //       Navigator.push(
                //           context,
                //           PageTransition(
                //               child: NotificationPage(),
                //               type: PageTransitionType.leftToRight));
                //       ScaffoldMessenger.of(context).showSnackBar(snackBar);
                //     }),

                CircularButton(
                    icon: Icon(Icons.search),
                    onPressed: () {
                      Navigator.pushNamed(context, MyRoutes.searchRoute);
                      ScaffoldMessenger.of(context).showSnackBar(snackBar);
                    })
              ],
            ),

 body: TabBarView(
          controller: _tabController,
