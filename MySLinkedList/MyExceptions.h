#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H
#include<string>
using namespace std;


class RuntimeException {
private:
	string errorMsg;
public:
	RuntimeException(const string& err) {
		errorMsg = err;
	}
	string getMessage() const { return errorMsg; }
};
class LinkedException : public RuntimeException {
public:  LinkedException(const string& err) : RuntimeException(err) {}
};
#endif

