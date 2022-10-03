import 'package:flutter/material.dart';

class CustomFormTextField extends StatelessWidget {
  CustomFormTextField(
      {Key? key,
      required this.title,
      this.subTitle,
      required this.controller,
      required this.inputType,
      this.maxLine})
      : super(key: key);
  String title;
  String? subTitle;
  TextEditingController controller;
  TextInputType inputType;
  int? maxLine;

  @override
  Widget build(BuildContext context) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Container(
          margin: const EdgeInsets.symmetric(horizontal: 10.0),
          decoration: BoxDecoration(color: Colors.grey.withOpacity(0.5)),
          child: Stack(
            children: [
              Padding(
                padding: const EdgeInsets.only(top: 10.0, left: 5.0),
                child: TextFormField(
                  controller: controller,
                  cursorColor: Colors.red,
                  keyboardType: inputType,
                  maxLines: maxLine ?? 1,
                  obscureText:
                      inputType == TextInputType.visiblePassword ? true : false,
                  decoration: const InputDecoration(
                    border: InputBorder.none,
                    focusedBorder: InputBorder.none,
                    enabledBorder: InputBorder.none,
                    errorBorder: InputBorder.none,
                    disabledBorder: InputBorder.none,
                    contentPadding: EdgeInsets.only(
                        left: 0, bottom: 11, top: 11, right: 15),
                  ),
                ),
              ),
              Positioned(
                left: 5,
                top: 5,
                child: Text(
                  title,
                  style: const TextStyle(
                      color: Colors.red,
                      fontSize: 14,
                      fontWeight: FontWeight.w300),
                ),
              ),
            ],
          ),
        ),
        subTitle != null
            ? Padding(
                padding: const EdgeInsets.only(left: 15.0, top: 5.0),
                child: Text(
                  subTitle!,
                  style: const TextStyle(
                      color: Colors.black,
                      fontSize: 12,
                      fontWeight: FontWeight.w200),
                ),
              )
            : Container(),
      ],
    );
  }
}
