#include <iostream>
#include <cmath>


using namespace std;

/*
*	problem ) http://darjeeling.chobi.net/dark_cpp.html
*	wandbox page ) http://melpon.org/wandbox/permlink/aK1uuaXtnKv5DfS7
*	use compiler ) gcc 5.1.0 and MSVS 2015 Community
*/

/*
*	�}�W�b�N�i���o�[���̂܂܂̉��炵���R�[�h�ł��邪�A���̒��x�̒Z���Ȃ���ɖ��Ȃ��Ɣ��f���A
*	���̂܂܂ɂ��Ă������ƂɁB
*	sin �ɓn���p�x�̕ϊ���Y��ăL���h���Ă��܂���
*/

auto main( void ) -> int
{
	int a {}, b {}, c {};
	cin >> a >> b >> c;

	cout << ( a * b * sin( ( c / 180.0 ) * 3.1415926535 ) / 2.0 ) << endl;
}
