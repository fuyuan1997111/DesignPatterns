#include "SempleFactory.h"

//×¢²á ´´½¨º¯Êý
REG_CLASS(ImplOne);
REG_CLASS(ImplTwo);


int main()
{
	Api* _api = Factory::createApi();
	_api->test("Fectory");

	return 0;
}