#include<istream>
using namespace std;
bool isSubsequence(char* s, char* t) {
	while (*s && *t) {
		if (*s == *t) {
			s++;
		}
		t++;
	}
	if (*s == '\0')
		return true;
	return false;
}
int main() {

	return 0;
}