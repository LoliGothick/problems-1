#include <iostream>

using namespace std;

/*
*	problem ) http://darjeeling.chobi.net/problem_2.html
*	wandbox page ) http://melpon.org/wandbox/permlink/6uGPgpASOWS40B4c
*	use compiler ) gcc 5.1.0 and MSVS 2015 Community
*/

/*
*	「なんだこれ簡単だろｗｗｗ」と思っていたけど、三角形の成立条件をまじめに考える必要があり
*	ちょっと考えた。
*	if文のネストと ?: のどちらが良いか考えた結果、汚らしいが幾つも　「cout << ～～」を書かなくてよい
*	こちらにした。
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

