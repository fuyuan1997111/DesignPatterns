#include "SempleFactory.h"

//ע�� ��������
REG_CLASS(ImplOne);
REG_CLASS(ImplTwo);


int main()
{
	Api* _api = Factory::createApi();
	_api->test("Fectory");

	return 0;
}