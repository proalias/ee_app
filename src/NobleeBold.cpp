#include "NobleeBold.h"

using namespace ci;
using namespace std;

NobleeBold::NobleeBold(void)
{
	// BUILD ALL THE POINTS FOR EACH CHAR IN THE FONT

	Vec2f a[] = { Vec2f(4.95,27.95),Vec2f(6.45,24.55),Vec2f(7.95,21.25),Vec2f(9.45,17.85),Vec2f(10.95,14.45),Vec2f(12.45,11),Vec2f(14.05,14.5),Vec2f(15.55,17.8),Vec2f(17.05,21.25),Vec2f(18.55,24.55),Vec2f(20.1,28),Vec2f(15.9,23.25),Vec2f(12.6,23.25),Vec2f(9.3,23.25) };
	A = std::vector<Vec2f>( a, a+(sizeof(a)/sizeof(a[0])) );

	Vec2f b[] = { Vec2f(5.75,11.1),Vec2f(5.75,14.5),Vec2f(5.75,17.9),Vec2f(5.75,21.3),Vec2f(5.75,24.6),Vec2f(5.75,28),Vec2f(9.05,11.1),Vec2f(12.35,11.1),Vec2f(15.75,11.5),Vec2f(17.65,14.3),Vec2f(17.15,17.4),Vec2f(14.85,19.5),Vec2f(17.55,21.6),Vec2f(11.85,19.5),Vec2f(8.65,19.5),Vec2f(18.05,24.7),Vec2f(16.05,27.5),Vec2f(12.45,28),Vec2f(16.05,27.5),Vec2f(9.15,28) };
	B = std::vector<Vec2f>( b, b+(sizeof(b)/sizeof(b[0])) );
	
	Vec2f c[] = { Vec2f(17.65,11.5),Vec2f(14.55,10.8),Vec2f(11.25,11),Vec2f(8.4,12.4),Vec2f(6.25,14.9),Vec2f(5.15,17.85),Vec2f(5.15,21.15),Vec2f(6.25,24.05),Vec2f(8.45,26.5),Vec2f(11.25,27.95),Vec2f(14.55,28.05),Vec2f(17.75,27.45) };
	C = std::vector<Vec2f>( c, c+(sizeof(c)/sizeof(c[0])) );

	Vec2f d[] = { Vec2f(5.75,11.05),Vec2f(5.75,14.45),Vec2f(5.75,17.85),Vec2f(5.75,21.15),Vec2f(5.75,24.55),Vec2f(5.75,27.95),Vec2f(9.05,11.05),Vec2f(12.55,11.05),Vec2f(15.65,12.35),Vec2f(17.95,14.65),Vec2f(19.25,17.85),Vec2f(19.25,21.25),Vec2f(17.95,24.35),Vec2f(15.65,26.65),Vec2f(12.55,27.95),Vec2f(9.15,27.95) };
	D = std::vector<Vec2f>( d, d+(sizeof(d)/sizeof(d[0])) );

	Vec2f e[] = { Vec2f(5.75,11.05),Vec2f(5.75,14.45),Vec2f(5.75,17.85),Vec2f(5.75,21.15),Vec2f(5.75,24.55),Vec2f(5.75,27.95),Vec2f(9.05,11.05),Vec2f(12.35,11.05),Vec2f(15.55,11.05),Vec2f(8.15,19.55),Vec2f(11.45,19.55),Vec2f(14.65,19.55),Vec2f(9.05,27.95),Vec2f(12.35,27.95),Vec2f(15.55,27.95) };
	E = std::vector<Vec2f>( e, e+(sizeof(e)/sizeof(e[0])) );

	Vec2f f[] = { Vec2f(5.75,11.05),Vec2f(5.75,14.45),Vec2f(5.75,17.85),Vec2f(5.75,21.15),Vec2f(5.75,24.55),Vec2f(5.75,27.95),Vec2f(9.05,11.05),Vec2f(12.35,11.05),Vec2f(15.55,11.05),Vec2f(8.15,19.55),Vec2f(11.45,19.55),Vec2f(14.65,19.55) };
	F = std::vector<Vec2f>( f, f+(sizeof(f)/sizeof(f[0])) );

	Vec2f g[] = { Vec2f(18.7,12.05),Vec2f(15.7,10.85),Vec2f(12.4,10.85),Vec2f(9.3,12.05),Vec2f(6.9,14.15),Vec2f(5.45,17.15),Vec2f(5.15,20.4),Vec2f(6.1,23.5),Vec2f(8,26),Vec2f(10.6,27.7),Vec2f(14,28.4),Vec2f(17.1,27.9),Vec2f(19.9,26.3),Vec2f(20.1,23),Vec2f(20.1,19.8),Vec2f(16.8,19.8),Vec2f(13.5,19.8) };
	G = std::vector<Vec2f>( g, g+(sizeof(g)/sizeof(g[0])) );

	Vec2f h[] = { Vec2f(5.75,11.05),Vec2f(5.75,14.45),Vec2f(5.75,17.85),Vec2f(5.75,21.15),Vec2f(5.75,24.55),Vec2f(5.75,27.95),Vec2f(9.15,19.55),Vec2f(12.55,19.55),Vec2f(15.85,19.55),Vec2f(19.35,11.05),Vec2f(19.35,14.45),Vec2f(19.35,17.85),Vec2f(19.35,21.15),Vec2f(19.35,24.55),Vec2f(19.35,27.95) };
	H = std::vector<Vec2f>( h, h+(sizeof(h)/sizeof(h[0])) );

	Vec2f i[] = { Vec2f(8.55,11.05),Vec2f(5.25,11.05),Vec2f(11.85,11.05),Vec2f(8.55,14.45),Vec2f(8.55,17.85),Vec2f(8.55,21.15),Vec2f(8.55,24.55),Vec2f(8.55,27.95),Vec2f(5.25,27.95),Vec2f(11.85,27.95) };
	I = std::vector<Vec2f>( i, i+(sizeof(i)/sizeof(i[0])) );

	Vec2f j[] = { Vec2f(11.15,11.05),Vec2f(7.85,11.05),Vec2f(14.35,11.05),Vec2f(14.35,14.35),Vec2f(14.35,17.85),Vec2f(14.35,21.15),Vec2f(14.35,24.55),Vec2f(12.65,27.05),Vec2f(9.55,27.95),Vec2f(6.65,27.05),Vec2f(5.05,24.45) };
	J = std::vector<Vec2f>( j, j+(sizeof(j)/sizeof(j[0])) );

	Vec2f k[] = { Vec2f(5.75,11.05),Vec2f(5.75,14.45),Vec2f(5.75,17.85),Vec2f(5.75,21.15),Vec2f(5.75,24.55),Vec2f(5.75,27.95),Vec2f(8.95,19.75),Vec2f(10.75,17.75),Vec2f(13.05,15.85),Vec2f(15.45,13.45),Vec2f(17.75,11.05),Vec2f(10.75,21.35),Vec2f(13.05,23.45),Vec2f(15.45,25.75),Vec2f(17.75,27.95) };
	K = std::vector<Vec2f>( k, k+(sizeof(k)/sizeof(k[0])) );

	Vec2f l[] = { Vec2f(5.75,11.05),Vec2f(5.75,14.45),Vec2f(5.75,17.85),Vec2f(5.75,21.15),Vec2f(5.75,24.55),Vec2f(5.75,27.95),Vec2f(9.05,27.95),Vec2f(12.35,27.95),Vec2f(15.55,27.95) };
	L = std::vector<Vec2f>( l, l+(sizeof(l)/sizeof(l[0])) );

	Vec2f m[] = { Vec2f(5.75,11.05),Vec2f(5.75,14.45),Vec2f(5.75,17.85),Vec2f(5.75,21.15),Vec2f(5.75,24.55),Vec2f(5.75,27.95),Vec2f(7.95,13.55),Vec2f(10.05,16.4),Vec2f(12.15,19.4),Vec2f(14.25,22.5),Vec2f(16.35,19.4),Vec2f(18.45,16.4),Vec2f(20.55,13.55),Vec2f(22.95,11.05),Vec2f(22.95,14.45),Vec2f(22.95,17.85),Vec2f(22.95,21.15),Vec2f(22.95,24.55),Vec2f(22.95,27.95) };
	M = std::vector<Vec2f>( m, m+(sizeof(m)/sizeof(m[0])) );

	Vec2f n[] = { Vec2f(5.85,11.05),Vec2f(5.65,14.15),Vec2f(5.75,17.65),Vec2f(5.65,21.05),Vec2f(5.75,24.55),Vec2f(5.75,27.95),Vec2f(7.95,13.55),Vec2f(10.25,16.55),Vec2f(12.55,19.55),Vec2f(14.85,22.55),Vec2f(17.05,25.6),Vec2f(19.5,28.1),Vec2f(19.7,24.9),Vec2f(19.6,21.5),Vec2f(19.6,18),Vec2f(19.6,14.5),Vec2f(19.6,18),Vec2f(19.6,11.1) };
	N = std::vector<Vec2f>( n, n+(sizeof(n)/sizeof(n[0])) );

	Vec2f o[] = { Vec2f(14,10.7),Vec2f(17.2,11.3),Vec2f(20,13),Vec2f(22,15.7),Vec2f(22.8,18.8),Vec2f(22.5,22),Vec2f(21,25),Vec2f(18.6,27.1),Vec2f(15.7,28.2),Vec2f(12.3,28.2),Vec2f(9.3,27.1),Vec2f(6.9,24.9),Vec2f(5.4,22),Vec2f(5.1,18.8),Vec2f(6,15.7),Vec2f(7.9,13),Vec2f(10.75,11.3) };
	O = std::vector<Vec2f>( o, o+(sizeof(o)/sizeof(o[0])) );

	Vec2f p[] = { Vec2f(5.75,11),Vec2f(5.75,14.5),Vec2f(5.75,17.9),Vec2f(5.75,21.3),Vec2f(5.75,24.6),Vec2f(5.75,28),Vec2f(9.15,11),Vec2f(12.55,11.1),Vec2f(16.05,11.5),Vec2f(18.05,14.3),Vec2f(17.95,17.9),Vec2f(15.95,20.7),Vec2f(12.45,21.2),Vec2f(9.05,21.2) };
	P = std::vector<Vec2f>( p, p+(sizeof(p)/sizeof(p[0])) );

	Vec2f q[] = { Vec2f(21.4,32.8),Vec2f(18.3,31.4),Vec2f(15.3,29.8),Vec2f(12.3,28.3),Vec2f(9.3,27.1),Vec2f(6.9,24.9),Vec2f(5.4,22),Vec2f(5.1,18.8),Vec2f(6,15.7),Vec2f(7.9,13),Vec2f(10.75,11.3),Vec2f(14,10.7),Vec2f(17.2,11.3),Vec2f(20,13),Vec2f(22,15.7),Vec2f(22.8,18.8),Vec2f(22.5,22),Vec2f(21,25),Vec2f(18.7,27),Vec2f(15.7,28.2) };
	Q = std::vector<Vec2f>( q, q+(sizeof(q)/sizeof(q[0])) );

	Vec2f r[] = { Vec2f(5.75,11),Vec2f(5.75,14.5),Vec2f(5.75,17.9),Vec2f(5.75,21.3),Vec2f(5.75,24.6),Vec2f(5.75,28),Vec2f(9.15,11),Vec2f(12.45,11.1),Vec2f(16.05,11.5),Vec2f(17.95,14.3),Vec2f(17.95,17.9),Vec2f(15.95,20.6),Vec2f(12.55,21.2),Vec2f(9.05,21.2),Vec2f(12.85,22.7),Vec2f(15.35,25.3),Vec2f(17.95,28) };
	R = std::vector<Vec2f>( r, r+(sizeof(r)/sizeof(r[0])) );

	Vec2f s[] = { Vec2f(17.15,13.4),Vec2f(14.55,11.4),Vec2f(11.55,10.8),Vec2f(8.45,11.3),Vec2f(6.05,13.3),Vec2f(5.75,16.3),Vec2f(8.05,18.5),Vec2f(11.25,19.3),Vec2f(14.25,19.9),Vec2f(17.05,21.3),Vec2f(17.95,24.3),Vec2f(16.45,26.95),Vec2f(13.45,28.15),Vec2f(10.35,28.1),Vec2f(7.3,26.95),Vec2f(5.05,24.8) };
	S = std::vector<Vec2f>( s, s+(sizeof(s)/sizeof(s[0])) );

	Vec2f t[] = { Vec2f(11.65,11.05),Vec2f(4.85,11.05),Vec2f(8.25,11.05),Vec2f(18.45,11.05),Vec2f(15.05,11.05),Vec2f(11.65,14.45),Vec2f(11.65,17.85),Vec2f(11.65,21.15),Vec2f(11.65,24.55),Vec2f(11.65,27.95) };
	T = std::vector<Vec2f>( t, t+(sizeof(t)/sizeof(t[0])) );

	Vec2f u[] = { Vec2f(5.65,11.05),Vec2f(5.65,14.45),Vec2f(5.65,17.75),Vec2f(5.65,21.15),Vec2f(6.45,24.35),Vec2f(8.45,26.75),Vec2f(11.35,28.05),Vec2f(14.55,28.05),Vec2f(17.45,26.75),Vec2f(19.35,24.25),Vec2f(20.15,21.25),Vec2f(20.15,17.85),Vec2f(20.15,14.35),Vec2f(20.15,11.05) };
	U = std::vector<Vec2f>( u, u+(sizeof(u)/sizeof(u[0])) );

	Vec2f v[] = { Vec2f(5.05,11.05),Vec2f(6.45,14.45),Vec2f(8.05,17.85),Vec2f(9.45,21.15),Vec2f(10.95,24.55),Vec2f(12.45,27.95),Vec2f(14.05,24.65),Vec2f(15.55,21.25),Vec2f(17.05,17.85),Vec2f(18.55,14.45),Vec2f(20.15,11.05) };
	V = std::vector<Vec2f>( v, v+(sizeof(v)/sizeof(v[0])) );

	Vec2f w[] = { Vec2f(5.05,11.05),Vec2f(5.95,14.45),Vec2f(6.85,17.85),Vec2f(7.85,21.15),Vec2f(8.75,24.55),Vec2f(9.75,27.95),Vec2f(11.05,24.65),Vec2f(12.35,21.25),Vec2f(13.65,17.85),Vec2f(14.95,14.45),Vec2f(16.25,11.05),Vec2f(17.65,14.45),Vec2f(18.85,17.85),Vec2f(20.15,21.15),Vec2f(21.45,24.55),Vec2f(22.85,27.95),Vec2f(23.75,24.65),Vec2f(24.75,21.25),Vec2f(25.65,17.85),Vec2f(26.65,14.45),Vec2f(27.55,11.05) };
	W = std::vector<Vec2f>( w, w+(sizeof(w)/sizeof(w[0])) );

	Vec2f x[] = { Vec2f(5.3,11.05),Vec2f(7.6,13.95),Vec2f(9.7,16.65),Vec2f(11.9,19.25),Vec2f(14.2,22.35),Vec2f(16.3,25.15),Vec2f(18.6,27.95),Vec2f(18.6,11.05),Vec2f(16.3,13.95),Vec2f(14.2,16.65),Vec2f(9.7,22.35),Vec2f(7.5,25.15),Vec2f(5.3,27.95) };
	X = std::vector<Vec2f>( x, x+(sizeof(x)/sizeof(x[0])) );

	Vec2f y[] = { Vec2f(4.85,11),Vec2f(6.95,13.6),Vec2f(8.95,16.1),Vec2f(10.95,18.6),Vec2f(10.95,18.6),Vec2f(20.35,11),Vec2f(18.25,13.6),Vec2f(16.25,16.1),Vec2f(14.25,18.6),Vec2f(14.25,18.6),Vec2f(12.65,21.3),Vec2f(12.65,24.6),Vec2f(12.65,28) };
	Y = std::vector<Vec2f>( y, y+(sizeof(y)/sizeof(y[0])) );

	Vec2f z[] = { Vec2f(5.25,11.1),Vec2f(8.75,11.1),Vec2f(12.15,11.1),Vec2f(15.55,11.1),Vec2f(13.75,13.9),Vec2f(12.05,16.8),Vec2f(10.45,19.5),Vec2f(8.75,22.35),Vec2f(6.95,25.15),Vec2f(5.25,28),Vec2f(8.75,28),Vec2f(12.15,28),Vec2f(15.55,28) };
	Z = std::vector<Vec2f>( z, z+(sizeof(z)/sizeof(z[0])) );

	Vec2f zero[] = { Vec2f(11.55,10.7),Vec2f(14.75,11.8),Vec2f(16.75,14.4),Vec2f(17.65,17.8),Vec2f(17.65,21.2),Vec2f(16.75,24.6),Vec2f(14.65,27.2),Vec2f(11.55,28.3),Vec2f(8.45,27.2),Vec2f(6.25,24.6),Vec2f(5.45,21.3),Vec2f(5.45,17.8),Vec2f(6.25,14.5),Vec2f(8.35,11.8) };
	ZERO = std::vector<Vec2f>( zero, zero+(sizeof(zero)/sizeof(zero[0])) );

	Vec2f one[] = { Vec2f(5,12.45),Vec2f(8.3,11.05),Vec2f(8.3,14.45),Vec2f(8.3,17.85),Vec2f(8.3,21.15),Vec2f(8.3,24.55),Vec2f(8.3,27.95) };
	ONE = std::vector<Vec2f>( one, one+(sizeof(one)/sizeof(one[0])) );

	Vec2f two[] = { Vec2f(5.4,13.2),Vec2f(8,11.15),Vec2f(11.55,10.85),Vec2f(14.75,12.45),Vec2f(15.7,15.75),Vec2f(14.4,19.05),Vec2f(11.4,20.75),Vec2f(8.3,22.45),Vec2f(5.7,24.65),Vec2f(5.1,27.95),Vec2f(8.5,27.95),Vec2f(11.9,27.95),Vec2f(15.3,27.95) };
	TWO = std::vector<Vec2f>( two, two+(sizeof(two)/sizeof(two[0])) );
	
	Vec2f three[] = { Vec2f(5.35,13.3),Vec2f(7.75,11.3),Vec2f(10.95,10.8),Vec2f(14.05,11.8),Vec2f(15.35,14.6),Vec2f(14.55,17.6),Vec2f(12.25,19.5),Vec2f(9.55,19.5),Vec2f(14.95,21.4),Vec2f(15.35,24.7),Vec2f(13.55,27.4),Vec2f(10.35,28.3),Vec2f(7.15,27.6),Vec2f(5.05,25.1) };
	THREE = std::vector<Vec2f>( three, three+(sizeof(three)/sizeof(three[0])) );

	Vec2f four[] = { Vec2f(18.25,23.2),Vec2f(14.75,23.2),Vec2f(11.25,23.2),Vec2f(8.15,23.2),Vec2f(4.95,23.2),Vec2f(6.65,20.8),Vec2f(8.65,18.25),Vec2f(10.55,15.55),Vec2f(12.45,13.05),Vec2f(14.55,10.75),Vec2f(14.75,14.45),Vec2f(14.75,17.85),Vec2f(14.65,20.95),Vec2f(14.75,24.75),Vec2f(14.75,28.05) };
	FOUR = std::vector<Vec2f>( four, four+(sizeof(four)/sizeof(four[0])) );

	Vec2f five[] = { Vec2f(13.1,11),Vec2f(9.6,11),Vec2f(6.3,11),Vec2f(6,14.7),Vec2f(5.7,18.3),Vec2f(9.2,17.8),Vec2f(9.2,17.8),Vec2f(12.35,18.05),Vec2f(12.35,18.05),Vec2f(14.75,20.15),Vec2f(14.75,20.15),Vec2f(15.45,23.45),Vec2f(15.45,23.45),Vec2f(14.25,26.45),Vec2f(14.25,26.45),Vec2f(14.25,26.45),Vec2f(11.4,28.2),Vec2f(7.9,28),Vec2f(5.1,26.1) };
	FIVE = std::vector<Vec2f>( five, five+(sizeof(five)/sizeof(five[0])) );

	Vec2f six[] = { Vec2f(13.55,10.7),Vec2f(10.45,12.3),Vec2f(8.05,14.5),Vec2f(6.55,17.1),Vec2f(5.55,20),Vec2f(5.45,23.25),Vec2f(6.25,26.35),Vec2f(6.35,20),Vec2f(8.95,28.15),Vec2f(12.25,28.15),Vec2f(14.85,26.45),Vec2f(15.75,23.25),Vec2f(14.95,20.05),Vec2f(12.25,18.25),Vec2f(8.95,18.35) };
	SIX = std::vector<Vec2f>( six, six+(sizeof(six)/sizeof(six[0])) );

	Vec2f seven[] = { Vec2f(4.7,11.05),Vec2f(8.2,11.05),Vec2f(11.5,11.05),Vec2f(14.9,11.05),Vec2f(13.3,13.05),Vec2f(11.9,16.05),Vec2f(10.5,19.05),Vec2f(9,22.05),Vec2f(7.85,25.05),Vec2f(7,28) };
	SEVEN = std::vector<Vec2f>( seven, seven+(sizeof(seven)/sizeof(seven[0])) );

	Vec2f eight[] = { Vec2f(10.6,11.05),Vec2f(13.6,12.05),Vec2f(15.2,14.65),Vec2f(14.3,17.35),Vec2f(12.2,19.05),Vec2f(9.4,19.05),Vec2f(6.8,17.35),Vec2f(5.8,14.65),Vec2f(7.4,11.95),Vec2f(6.6,20.65),Vec2f(5.7,23.55),Vec2f(6.6,26.45),Vec2f(9.1,27.95),Vec2f(12.3,27.95),Vec2f(14.9,26.45),Vec2f(15.8,23.55),Vec2f(14.9,20.55) };
	EIGHT = std::vector<Vec2f>( eight, eight+(sizeof(eight)/sizeof(eight[0])) );

	Vec2f nine[] = { Vec2f(7.4,28),Vec2f(10.4,26.6),Vec2f(12.8,24.7),Vec2f(14.2,22),Vec2f(14.9,19.1),Vec2f(15.45,15.95),Vec2f(14.6,12.85),Vec2f(11.9,11.05),Vec2f(8.75,11.05),Vec2f(6.1,12.85),Vec2f(5.15,15.95),Vec2f(6,19.1),Vec2f(8.6,20.9),Vec2f(11.8,20.8) };
	NINE = std::vector<Vec2f>( nine, nine+(sizeof(nine)/sizeof(nine[0])) );

	Vec2f fullstop[] = { Vec2f(5.15,28) };
	FULL_STOP = std::vector<Vec2f>( fullstop, fullstop+(sizeof(fullstop)/sizeof(fullstop[0])) );

	Vec2f greaterthan[] = { Vec2f(5.1,11.65),Vec2f(7.5,13.55),Vec2f(9.8,15.55),Vec2f(12.1,17.45),Vec2f(14.55,19.5),Vec2f(12.2,21.45),Vec2f(9.8,23.45),Vec2f(7.5,25.35),Vec2f(5.1,27.25) };
	GREATER_THAN = std::vector<Vec2f>( greaterthan, greaterthan+(sizeof(greaterthan)/sizeof(greaterthan[0])) );

	Vec2f lessthan[] = { Vec2f(14.6,11.65),Vec2f(12.15,13.65),Vec2f(9.85,15.55),Vec2f(7.45,17.55),Vec2f(5.1,19.5),Vec2f(7.45,21.45),Vec2f(9.85,23.35),Vec2f(12.15,25.35),Vec2f(14.55,27.25) };
	LESS_THAN = std::vector<Vec2f>( lessthan, lessthan+(sizeof(lessthan)/sizeof(lessthan[0])) );

	Vec2f questionmark[] = { Vec2f(5.1,12.6),Vec2f(8.2,11),Vec2f(11.4,11),Vec2f(14.2,13.35),Vec2f(14.2,16.7),Vec2f(12.05,19.4),Vec2f(9.4,21),Vec2f(9.4,28) };
	QUESTION_MARK = std::vector<Vec2f>( questionmark, questionmark+(sizeof(questionmark)/sizeof(questionmark[0])) );

	Vec2f exclamationmark[] = { Vec2f(5.8,11),Vec2f(5.8,14.4),Vec2f(5.8,17.8),Vec2f(5.8,21.2),Vec2f(5.8,28) };
	EXCLAMATION_MARK = std::vector<Vec2f>( exclamationmark, exclamationmark+(sizeof(exclamationmark)/sizeof(exclamationmark[0])) );

	Vec2f pound[] = { Vec2f(17.75,13.3),Vec2f(15.2,11.3),Vec2f(12.1,11),Vec2f(8.95,12.15),Vec2f(7.5,14.9),Vec2f(7.85,18.3),Vec2f(8.6,21.55),Vec2f(8.15,24.55),Vec2f(7.3,28),Vec2f(10.6,27.95),Vec2f(13.9,28),Vec2f(17.3,27.95),Vec2f(4.85,20.15),Vec2f(11.55,20.15),Vec2f(14.65,20.15) };
	POUND = std::vector<Vec2f>( pound, pound+(sizeof(pound)/sizeof(pound[0])) );

	Vec2f euro[] = { Vec2f(18,11.05),Vec2f(14.5,10.55),Vec2f(11.1,11.05),Vec2f(9.15,13.7),Vec2f(8.55,16.7),Vec2f(8.45,19.2),Vec2f(8.15,21.6),Vec2f(9.15,25.1),Vec2f(11.1,27.55),Vec2f(14.45,28.1),Vec2f(18.05,27.5),Vec2f(5.45,16.8),Vec2f(11.35,16.8),Vec2f(5.45,16.8),Vec2f(14.55,16.8),Vec2f(5.45,21.9),Vec2f(11.35,21.9),Vec2f(5.45,21.9),Vec2f(14.55,21.9) };
	EURO = std::vector<Vec2f>( euro, euro+(sizeof(euro)/sizeof(euro[0])) );

	Vec2f percentage[] = { Vec2f(18.35,12.85),Vec2f(15.95,15.55),Vec2f(13.55,18.25),Vec2f(11.1,20.85),Vec2f(8.65,23.6),Vec2f(6.3,26.25),Vec2f(6.1,11),Vec2f(9.5,11),Vec2f(4.9,14.1),Vec2f(7.75,16.25),Vec2f(10.6,14.2),Vec2f(16.9,22.7),Vec2f(19.7,24.9),Vec2f(13.9,24.9),Vec2f(15.15,28.05),Vec2f(18.5,28.05) };
	PERCENTAGE = std::vector<Vec2f>( percentage, percentage+(sizeof(percentage)/sizeof(percentage[0])) );

	Vec2f ampersand[] = { Vec2f(17.75,22.1),Vec2f(15.65,25.5),Vec2f(12.45,26.8),Vec2f(9.25,28),Vec2f(6.05,26.8),Vec2f(5.15,23.6),Vec2f(6.65,20.8),Vec2f(9.25,19.1),Vec2f(12.65,17.9),Vec2f(14.15,14.85),Vec2f(12.8,11.85),Vec2f(9.65,11.05),Vec2f(6.9,13),Vec2f(6.55,16.5),Vec2f(11.85,20.5),Vec2f(13.75,23.25),Vec2f(17.85,28) };
	AMPERSAND = std::vector<Vec2f>( ampersand, ampersand+(sizeof(ampersand)/sizeof(ampersand[0])) );

	Vec2f circumflex[] = { Vec2f(5.15,20.25),Vec2f(7.05,17.15),Vec2f(9.05,13.95),Vec2f(10.85,10.55),Vec2f(12.8,13.75),Vec2f(14.6,17.05),Vec2f(16.5,20.25) };
	CIRCUMFLEX = std::vector<Vec2f>( circumflex, circumflex+(sizeof(circumflex)/sizeof(circumflex[0])) );

	Vec2f atsymbol[] = { Vec2f(21.8,33.05),Vec2f(18.3,33.95),Vec2f(14.8,33.85),Vec2f(11.4,32.85),Vec2f(8.55,30.7),Vec2f(6.8,27.85),Vec2f(5.9,24.45),Vec2f(5.7,21.05),Vec2f(6.4,17.65),Vec2f(7.9,14.55),Vec2f(10.3,11.95),Vec2f(13.5,10.45),Vec2f(16.9,10.25),Vec2f(20.4,10.9),Vec2f(23.2,12.8),Vec2f(25.1,15.6),Vec2f(26.2,18.9),Vec2f(26.2,22.3),Vec2f(25.2,25.6),Vec2f(22.1,26.7),Vec2f(20.4,24.1),Vec2f(20.2,20.5),Vec2f(18.4,17.7),Vec2f(15.1,17.2),Vec2f(12.6,19.2),Vec2f(11.9,22.6),Vec2f(13.1,25.7),Vec2f(16.1,27.2) };
	AT_SYMBOL = std::vector<Vec2f>( atsymbol, atsymbol+(sizeof(atsymbol)/sizeof(atsymbol[0])) );

	Vec2f openbracket[] = { Vec2f(10.95,8.05),Vec2f(8.85,10.85),Vec2f(7.45,14.05),Vec2f(6.55,17.35),Vec2f(6.35,20.75),Vec2f(6.55,24.25),Vec2f(7.45,27.45),Vec2f(8.85,30.55),Vec2f(10.95,33.45) };
	OPEN_BRACKET = std::vector<Vec2f>( openbracket, openbracket+(sizeof(openbracket)/sizeof(openbracket[0])) );

	Vec2f closebracket[] = { Vec2f(3.55,8),Vec2f(5.55,10.8),Vec2f(6.95,14),Vec2f(7.85,17.3),Vec2f(8.15,20.8),Vec2f(7.95,24.2),Vec2f(6.95,27.6),Vec2f(5.65,30.6),Vec2f(3.45,33.5) };
	CLOSE_BRACKET = std::vector<Vec2f>( closebracket, closebracket+(sizeof(closebracket)/sizeof(closebracket[0])) );

	Vec2f plus[] = { Vec2f(11.95,12.7),Vec2f(11.95,16.2),Vec2f(11.95,19.4),Vec2f(11.95,22.9),Vec2f(11.95,26.3),Vec2f(5.2,19.45),Vec2f(8.6,19.45),Vec2f(15.3,19.45),Vec2f(18.7,19.45) };
	PLUS = std::vector<Vec2f>( plus, plus+(sizeof(plus)/sizeof(plus[0])) );

	Vec2f equals[] = { Vec2f(11.95,16.6),Vec2f(5.2,16.55),Vec2f(8.6,16.55),Vec2f(15.3,16.55),Vec2f(11.95,22.5),Vec2f(5.2,22.45),Vec2f(8.6,22.45),Vec2f(15.3,22.45) };
	EQUALS = std::vector<Vec2f>( equals, equals+(sizeof(equals)/sizeof(equals[0])) );

	Vec2f dash[] = { Vec2f(5.2,20.85),Vec2f(8.5,20.85) };
	DASH = std::vector<Vec2f>( dash, dash+(sizeof(dash)/sizeof(dash[0])) );

	Vec2f underscore[] = { Vec2f(10.45,32.4),Vec2f(3.7,32.35),Vec2f(7.1,32.35) };
	UNDERSCORE = std::vector<Vec2f>( underscore, underscore+(sizeof(underscore)/sizeof(underscore[0])) );

	Vec2f forwardslash[] = { Vec2f(9,16.5),Vec2f(11.45,10.4),Vec2f(10.25,13.45),Vec2f(7.75,19.55),Vec2f(5.2,25.7),Vec2f(6.45,22.65),Vec2f(3.95,28.75) };
	FORWARD_SLASH = std::vector<Vec2f>( forwardslash, forwardslash+(sizeof(forwardslash)/sizeof(forwardslash[0])) );

	Vec2f doublequote[] = { Vec2f(5.15,11.1),Vec2f(5.15,14.6),Vec2f(10.45,11.1),Vec2f(10.45,14.6) };
	DOUBLE_QUOTE = std::vector<Vec2f>( doublequote, doublequote+(sizeof(doublequote)/sizeof(doublequote[0])) );

	Vec2f singlequote[] = { Vec2f(5.15,11.1),Vec2f(5.15,14.6) };
	SINGLE_QUOTE = std::vector<Vec2f>( singlequote, singlequote+(sizeof(singlequote)/sizeof(singlequote[0])) );

	Vec2f colon[] = { Vec2f(5.15,17.9),Vec2f(5.15,28.1) };
	COLON = std::vector<Vec2f>( colon, colon+(sizeof(colon)/sizeof(colon[0])) );

	Vec2f semicolon[] = { Vec2f(5.25,17.8),Vec2f(5.25,28.1),Vec2f(4.25,31.2) };
	SEMI_COLON = std::vector<Vec2f>( semicolon, semicolon+(sizeof(semicolon)/sizeof(semicolon[0])) );

	Vec2f comma[] = { Vec2f(5.25,28.1),Vec2f(4.25,31.3) };
	COMMA = std::vector<Vec2f>( comma, comma+(sizeof(comma)/sizeof(comma[0])) );

	Vec2f hashtag[] = { Vec2f(11.7, 9.6), Vec2f(10.8, 12.7), Vec2f(9.85, 15.8), Vec2f(8.95, 18.75), Vec2f(7.85, 21.95), Vec2f(7.05, 24.9), Vec2f(6.1, 28), Vec2f(18.45, 9.6), Vec2f(17.55, 12.7), Vec2f(16.6, 15.8), Vec2f(15.65, 18.75), Vec2f(14.6, 21.95), Vec2f(13.8, 24.9), Vec2f(12.85, 28), Vec2f(6.6, 15.55), Vec2f(13.1, 15.55), Vec2f(19.55, 15.55), Vec2f(5.1, 22.2), Vec2f(11.5, 22.15), Vec2f(18.1, 22.2) };
	HASHTAG = std::vector<Vec2f>( hashtag, hashtag+(sizeof(hashtag)/sizeof(hashtag[0])) );

}