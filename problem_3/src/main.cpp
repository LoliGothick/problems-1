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
*	�����o�֐��������Ă��邩�ǂ������肷�郁�^�֐������߂ď������B
*	���łɁAcout ���o���邩�ǂ������肷�郁�^�֐������߂ď������B
*	�����āA�Ȃ���github�ɃR�~�b�g���ł��Ȃ��Ď���ł�B
*	�R���p�C����ʂ����߂ɖ�������������ł��ӂ�Ă���̂炢�ł��B
*/

/*
*	�����o�֐���print�����邩�ǂ����̔���
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
*	cout << value << endl; ���o����( operator << ���I�[�o�[���[�h���Ă��� )���ǂ����̔���
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
*	�����o�ϐ���print()���ĂԂ�[��
*/
template< typename T >
decltype(auto) print_impl( T&& t )
	-> decltype( t.print() )
{
	return t.print();
}

/*
*	cout �����[��
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
*	�������Ȃ���[��
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


// hoge_t::print() ���Ă�
struct hoge_t
{
	void print()
	{
		cout << "hoge_t::print()" << endl;
	}
};

// ����Ԃ�
struct huga_t
{
};

auto main( void ) -> int
{
	int&& t = 0;

	print( hoge_t {} );		// hoge_t::print() ���Ăяo��
	print( t );				// cout << t << endl; ������
	print( huga_t {} );		// �������Ȃ�

#if defined( _MSC_VER )
	cin >> string {};
#endif
}
