class App {
  constructor() {
    this.viewsNames = [];
    this.viewsViews = [];
    this.viewsControllers = [];
    this.view = '';
    this.controller = null;
    this.model = null;
    this.moveFactor = 50;
    this.balls = [];
    this.ballsDead = [];
    this.count = 0.00;
    this.frame = 0;
    this.rekord = 0.00;
    this.gameOver = false;
    this.playerLeft = null;
    this.playerTop = null;
    this.updateID = null;
    this.movePlayerLeft = false;
    this.movePlayerRight = false;
  }

  setModel(model) {
    this.model = JSON.parse(model);
  }

  addView(view) {
    this.viewsNames.push(view.name);
    this.viewsViews.push(view.view);
    this.viewsControllers.push(view.controller);
  }

  showView(viewName) {
    var ind = this.viewsNames.indexOf(viewName);
    if (ind != -1) {
      this.view = viewName;
      this.controller = this.viewsControllers[ind];
    }
    return this;
  }

  placeAt(id) {
    var ind = this.viewsNames.indexOf(this.view);
    if (ind != -1) {
      $('#'+id).empty().append(this.viewsViews[ind]);
      this.controller.init();
    }
  }
}