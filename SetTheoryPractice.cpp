#include <vector>
#include <iostream>
using namespace std;





vector<int> getVec() { // this gets the set of numbers the user wishes to enter
	cout << "Enter the amount of elements in the set" << endl;
	int amountOfElements;
	cin >> amountOfElements;
	int input;
	vector<int> vec(amountOfElements);

	for (int i = 0; i < amountOfElements; i++) { // adds the number they want to add to the set
		cout << "Enter element " << i + 1 << " ";
		cin >> input;
		vec[i] = input;
	}
	return vec;
}




void printSet(vector<int> vec) { // this prints the set

	for (int& it : vec) {
		cout << it << " ";
	}

	cout << endl;

}

bool alreadyChecked(vector<int> setA, int i, int counter) { // this function checks to see if the element they are checking in the set was already checked

	for(int j = counter - 1; j >= 0; j--){

		if (setA[j] == i) {
			return true;
		}
	}

	return false;
}

bool alreadyChecked(vector<int> setA, int i) {

	for (auto& j : setA) {
		if (j == i) {
			return true;
		}
	}

	return false;

}

vector<int> intersectionOfSets(vector<int> setA, vector<int> setB) { // this gets the intersectoin of the sets
	vector<int> intersect;
	int counter = 0;

	for (auto& i : setA) { // this iterates through the first set

		if (alreadyChecked(setA, i, counter++)) // This checkes each element to see if it was already checked for intersection
			continue;

		
		for (auto& j : setB) { // this iterates through the setB, and if the element is in setA and setB, then add it to the new vector
			if (i == j) {
				intersect.push_back(i);
				break;
			}
		}

	}

	return intersect;
}



vector<int> unionOfSets(vector<int> setA, vector<int> setB) { // this gets the union of the sets

	vector<int> unionSets;
	int counter = 0;
	
	for (auto& i : setA) { // iterates through the first set, and adds each element to the unionSet

		if (alreadyChecked(setA, i, counter++)) // if its already checked continue
			continue;

		unionSets.push_back(i);
	}

	counter = 0;

	int counter2 = 0;


	for (auto& j : setB) { // this iterates through the second set


		if (alreadyChecked(setA, j)) // if the number in the second set, was in the first set then continue
			continue;
		
		unionSets.push_back(j); // adds it to the union set
	}


	return unionSets;
}

void swap(int* x, int* y) { // this swaps the variables
	int temp = *x;
	*x = *y;
	*y = temp;
}

void selectionSort(vector<int>& set) { // this does a selection sort on the intersection and union set
	int minElement;

	for (int i = 0; i < set.size() - 1; i++) {
		minElement = i;

		for (int j = i + 1; j < set.size(); j++) {
			if (set[j] < set[minElement]) {
				minElement = j;
			}
		}

		swap(&set[minElement], &set[i]);

	}

}



int main() {
	
	vector<int> setA = getVec();
	vector<int> setB = getVec();
	
	cout << "\nThe elements in the first set are " << endl;
	printSet(setA); // prints setA

	cout << "\nThe elements in the second set are " << endl;
	printSet(setB); //prints setB
	
	vector<int> intersect = intersectionOfSets(setA, setB);
	vector<int> unionOfSet = unionOfSets(setA, setB);

	cout << "\nThe intersection of the sets is " << endl;

	if (!intersectionOfSets(setA, setB).empty()) { // this makes sure there is something in the intersection set, and then prints it
		printSet(intersect);
	}
	else { // if there is not, it must be the null set
		cout << "Null set " << endl;
	}

	cout << "\nThe union of the sets is " << endl;
	printSet(unionOfSet); // prints the union set

	selectionSort(intersect); // does a selection sort on the intersection and union sets
	selectionSort(unionOfSet);

	cout << "\nThe intersected list sorted is " << endl;
	printSet(intersect); // prints intersected sorted


	cout << "\nThe union list sorted is " << endl;
	printSet(unionOfSet); // prints union set sorted


}
