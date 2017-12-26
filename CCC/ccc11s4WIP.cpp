#include <iostream>

using namespace std;

long long patients[8];
long long blood[8];


int main() {
	// reading input
	long long count = 0, input;
	ios_base::sync_with_stdio(false);
	for (int i = 0; i<8; ++i) {
		cin >> input;
		blood[i] = input;
	}
	for (int i = 0; i<8; ++i) {
		cin >> input;
		patients[i] = input;
	}
	// separate code for O type blood - need to make sure positive blood is being used when possible
	long long typeOp, typeOn;
	typeOn = blood[0];
	if (patients[0] >= typeOn) {
		count += typeOn;
		typeOn = 0;
	}
	else {
		count += patients[0];
		typeOn -= patients[0];
	}
	typeOp= blood[1];
	if (patients[1] >= typeOn+typeOp) {
		count += typeOn + typeOp;
		typeOn = 0;
		typeOp = 0;
	}
	else {
		count +=patients[1];
		if (patients[1]-typeOp<=0){
			typeOp=0;
			typeOn -= (patients[1]-typeOp);
		}
		else{
			typeOp -= patients[1];
		}
	}
	long long remaining, negativeType;
	for (int i=2; i<8; ++i){
		if (i%2==0){ //negative blood types
			if (patients[i]>blood[i]){
				count +=blood[i];
				negativeType = 0;
			}
			else {
				remaining = blood[i]-patients[i];
				count += blood[i];
			}
		}
		else { // positive blood types
			
		}
	}

	// long long typeAp, typeAn;
	// typeAn = blood[2];
	// if (typeOn==0){
	// 	if (patients[2] >= typeAn) {
	// 		count += typeAn;
	// 		typeAn = 0;
	// 	}
	// 	else {
	// 		count += patients[2];
	// 		typeAn -= patients[2];
	// 	}
	// }


	
	
	// typeOp= blood[1];
	// if (patients[1] >= typeOn+typeOp) {
	// 	count += typeOn + typeOp;
	// 	typeOn = 0;
	// 	typeOp = 0;
	// }
	// else {
	// 	count +=patients[1];
	// 	if (patients[1]-typeOp<=0){
	// 		typeOp=0;
	// 		typeOn -= (patients[1]-typeOp);
	// 	}
	// 	else{
	// 		typeOp -= patients[1];
	// 	}
	// }




	// for (int i = 2; i < 4; ++i) {
	// 	typeA += blood[i];
	// 	if (patients[i] >= typeO + typeA) {
	// 		count = count + typeO + typeA;
	// 		typeO = 0;
	// 		typeA = 0;
	// 	}
	// 	else if (patients[i] >= typeA && patients[i] < typeA + typeO) {
	// 		count += patients[i];
	// 		typeO -= (patients[i] - typeA);
	// 		typeA = 0;
	// 	}
	// 	else if (patients[i] >= typeO && patients[i] < typeA + typeO) {
	// 		count += patients[i];
	// 		typeA -= (patients[i] - typeO);
	// 		typeO = 0;

	// 	}
	// 	else {
	// 		count += patients[i];
	// 		typeA -= patients[i];
	// 	}
	// }
		
	// for (int i = 4; i<6; ++i) {
	// 	typeB += blood[i];
	// 	if (patients[i] >= typeO + typeB) {
	// 		count = count + typeO + typeB;
	// 		typeO = 0;
	// 		typeB = 0;
	// 	}
	// 	else if (patients[i]>=typeB && patients[i]<typeB+typeO){
	// 		count += patients[i];
	// 		typeO -= (patients[i]-typeB);
	// 		typeB = 0;
	// 	}
	// 	else if (patients[i]>=typeO && patients[i]<typeB+typeO){
	// 		count += patients[i];
	// 		typeB -= (patients[i] - typeO);
	// 		typeO = 0;
			
	// 	}
	// 	else {
	// 		count += patients[i];
	// 		typeB -= patients[i];
	// 	}
	// }
	// remaining = typeO + typeA + typeB;
	// for (int i = 6; i < 8; ++i) {
	// 	remaining += blood[i];
	// 	if (patients[i] >= remaining) {
	// 		count += remaining;
	// 		remaining = 0;
	// 	}
	// 	else {
	// 		count += patients[i];
	// 		remaining -= patients[i];
	// 	}
	// }
	cout << count << endl;
	system("pause");
	return 0;
}