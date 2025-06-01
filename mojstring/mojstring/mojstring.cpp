#include<iostream>
#include <conio.h>

using namespace std;

class myString {
private:
	
	int Size = 0;
	char* string;
	

public:

	myString() {
		string = nullptr;
	}

	myString(const char *string) {
		int lentgh = strlen(string);

		this->Size = lentgh;
		this->string = new char[lentgh + 1];

		for (int i = 0; i < lentgh; i++) {
			this->string[i] = *(string+i);
		}
		this->string[lentgh] = '\0';
	}

	myString(const myString& other) {
		
		int length = strlen(other.string);
			this->string = new char[length + 1];

			for (int i = 0; i < length; i++) {
			this->string[i] = other.string[i];
		}

		this->string[length] = '\0';
		
	}

	myString operator =(const myString& other) {
		this->Size = other.Size;

		if (this->string != nullptr) {
			delete[] string;
		}

		this->string = new char[this->Size + 1];
		this->Size++;

		for (int i = 0; i < Size; i++) {
			this->string[i] = other.string[i];
		}
		return *this;
	}

	myString operator +(const myString& other) {
		this->Size = other.Size;

		myString tempString;

		int thisLength = strlen(this->string);
		int otherLength = strlen(other.string);

		tempString.string = new char[thisLength + otherLength + 1];
		
		for (int i = 0; i < thisLength; i++) {
			tempString.string[i] = this->string[i];
		}

		for (int i = 0; i < otherLength; i++) {
			tempString.string[i + thisLength] = other.string[i];
		}
		

		tempString.string[thisLength + otherLength] = '\0';

		tempString.Size = thisLength + otherLength;

		return tempString;
	}

	~myString() {
		//cout << "destructor is up " << this << endl;
		delete[] string;
	}

	void ShowString() {
		for (int i = 0; i < this->Size; i++) {
			cout << string[i];
		}
		cout << endl;
	}


};

int main(int argc, char* argv[]) {
	
	myString a("apple");
	myString b("bruh");
	a.ShowString();
	b.ShowString();


	myString c;
	c = a + b;
	c.ShowString();
	
	return 0;
}