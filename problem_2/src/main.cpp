#include <iostream>

using namespace std;

/*
*	problem ) http://darjeeling.chobi.net/problem_2.html
*	wandbox page ) http://melpon.org/wandbox/permlink/6uGPgpASOWS40B4c
*	use compiler ) gcc 5.1.0 and MSVS 2015 Community
*/

/*
*	�u�Ȃ񂾂���ȒP���낗�����v�Ǝv���Ă������ǁA�O�p�`�̐����������܂��߂ɍl����K�v������
*	������ƍl�����B
*	if���̃l�X�g�� ?: �̂ǂ��炪�ǂ����l�������ʁA���炵��������@�ucout << �`�`�v�������Ȃ��Ă悢
*	������ɂ����B
*/

auto main( void ) -> int
{
	int a {}, b {}, c {};
	cin >> a >> b >> c;

	cout
		<<
		(
			a*a + b*b == c*c
			? "1"
			: ( ( a < b + c ) && ( b < a + c ) && ( c < a + b ) )
			? "0"
			: "-1"
		)
		<< endl;
}

