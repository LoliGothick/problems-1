#include <iostream>
#include <type_traits>
#include <string>

using namespace std;

/*
*	problem ) http://darjeeling.chobi.net/problem_3.html
*	wandbox page ) http://melpon.org/wandbox/permlink/0ZrM2BYSU5cFr8hc
*	use compiler ) gcc 5.1.0 and MSVS 2015 Community
*/

/*
*	メンバ関数を持っているかどうか判定するメタ関数を初めて書いた。
*	ついでに、cout が出来るかどうか判定するメタ関数も初めて書いた。
*	そして、なぜかgithubにコミットができなくて死んでる。
*	コンパイルを通すために無理矢理書いた感であふれているのつらいです。
*/

/*
*	メンバ関数にprintがあるかどうかの判定
*/
template< typename T >
class has_print
{
	template< typename U >
	static auto check( U u ) -> decltype( u.print(), std::true_type {} );

	static auto check( ... )->std::false_type;

public:

	static const bool value = decltype( check( std::declval< T >() ) )::value;
};

/*
*	cout << value << endl; が出来る( operator << がオーバーロードしてある )かどうかの判定
*/
template< typename T >
class can_output
{
	template< typename U >
	static auto check( U u ) -> decltype( cout << u, std::true_type {} );

	static auto check( ... )->std::false_type;

public:

	static const bool value = decltype( check( std::declval< T >() ) )::value;
};

/*
*	メンバ変数のprint()を呼ぶやーつ
*/
template< typename T >
decltype(auto) print_impl( T&& t )
	-> decltype( t.print() )
{
	return t.print();
}

/*
*	cout するやーつ
*/
template< typename T >
decltype(auto) print_impl( T&& t )
	-> typename std::enable_if_t
	<
		!has_print< T >::value &&
		can_output< T >::value
	>
{
	return cout << t << endl;
}

/*
*	何もしないやーつ
*/
template< typename T >
auto print_impl( T&& )
	-> typename std::enable_if_t
	<
		!has_print< T >::value &&
		!can_output< T >::value
	>
{
}

template< typename T >
decltype(auto) print( T&& t )
{
	print_impl( t );
}


// hoge_t::print() を呼ぶ
struct hoge_t
{
	void print()
	{
		cout << "hoge_t::print()" << endl;
	}
};

// 握りつぶす
struct huga_t
{
};

auto main( void ) -> int
{
	int&& t = 0;

	print( hoge_t {} );		// hoge_t::print() を呼び出す
	print( t );				// cout << t << endl; をする
	print( huga_t {} );		// 何もしない

#if defined( _MSC_VER )
	cin >> string {};
#endif
}
