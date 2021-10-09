class Prediction {
  final double confidence;
  final int index;
  final String label;

  Prediction({this.confidence, this.index, this.label});

  factory Prediction.fromJson(Map<dynamic, dynamic> json) {
    return Prediction(
      confidence: json['confidence'],
      index: json['index'],
      label: json['label'],
    );
  }
}
