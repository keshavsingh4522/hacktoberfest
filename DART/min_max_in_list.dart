// Program to finding Minimum and Maximum Value in a List

// Main function
void main() {
	
// Creating a Dart list
var dartList = [11, 21, 11, 14, 36, 67];
	
// Assigning the largestValue and smallestValue
var largestValue = dartList[0];
var smallestValue = dartList[0];

for (var i = 0; i < dartList.length; i++) {
	
	// Checking for largest value in the list
	if (dartList[i] > largestValue) {
	largestValue = dartList[i];
	}
	
	// Checking for smallest value in the list
	if (dartList[i] < smallestValue) {
	smallestValue = dartList[i];
	}
}

// displaying the values
print("Smallest value in the list : $smallestValue");
print("Largest value in the list : $largestValue");
}
