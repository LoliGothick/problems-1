#include <iostream>
#include <cmath>


using namespace std;

/*
*	problem ) http://darjeeling.chobi.net/dark_cpp.html
*	wandbox page ) http://melpon.org/wandbox/permlink/aK1uuaXtnKv5DfS7
*	use compiler ) gcc 5.1.0 and MSVS 2015 Community
*/

/*
*	マジックナンバーそのままの汚らしいコードであるが、この程度の短さなら特に問題ないと判断し、
*	そのままにしておくことに。
*	sin に渡す角度の変換を忘れてキョドってしまった
*/

auto main( void ) -> int
{
	int a {}, b {}, c {};
	cin >> a >> b >> c;

	cout << ( a * b * sin( ( c / 180.0 ) * 3.1415926535 ) / 2.0 ) << endl;
}
