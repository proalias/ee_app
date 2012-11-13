#include "NobleeRegular.h"

NobleeRegular::NobleeRegular(void)
{
	// BUILD ALL THE POINTS FOR EACH CHAR IN THE FONT

	// TODO - A IS WRONG POINTS ON REGULAR> USES C MUST HAVE GOT LOST IN TESTS. NEED TO GET IT
	Vec2f a[] = { Vec2f(19.85f, 12.45f), Vec2f(18.0f, 11.1f), Vec2f(15.8f, 10.3f), Vec2f(13.55f, 10.0f), Vec2f(11.35f, 10.3f), Vec2f(9.2f, 11.1f), Vec2f(7.35f, 12.45f), Vec2f(5.85f, 14.15), Vec2f(4.8f, 16.2), Vec2f(4.2f, 18.4), Vec2f(4.2f, 20.65), Vec2f(4.75f, 22.9), Vec2f(5.8f, 24.95), Vec2f(7.3f, 26.7), Vec2f(9.15f, 28.05), Vec2f(11.35f, 28.85), Vec2f(13.55f, 29.1), Vec2f(15.9f, 28.85), Vec2f(18.0f, 28.05), Vec2f(19.9f, 26.7) };
	A = std::vector<Vec2f>( a, a+(sizeof(a)/sizeof(a[0])) );

	/*
	Vec2f b[] = {Vec2f(4.8f, 10.1), Vec2f(4.75, 12.45), Vec2f(4.75, 14.8), Vec2f(4.75, 17.2), Vec2f(4.75, 19.55), Vec2f(4.75, 21.9), Vec2f(4.75, 24.25), Vec2f(4.75, 26.65), Vec2f(4.75, 29), Vec2f(7.05, 10.1), Vec2f(7.1, 19.55), Vec2f(7.05, 29), Vec2f(9.35, 10.1), Vec2f(9.35, 19.55), Vec2f(9.3, 29), Vec2f(11.6, 10.1), Vec2f(11.6, 19.55), Vec2f(11.55, 29), Vec2f(13.9, 10.25), Vec2f(13.95, 19.55), Vec2f(13.8, 29), Vec2f(16, 10.8), Vec2f(15.95, 18.45), Vec2f(15.95, 20.6), Vec2f(16.05, 28.5), Vec2f(17.5, 12.5), Vec2f(17.75, 14.65), Vec2f(17.4, 16.85), Vec2f(17.4, 22.2), Vec2f(17.9, 24.45), Vec2f(17.5, 26.75) };
	B = std::vector<Vec2f>( b, b+(sizeof(b)/sizeof(b[0])) );

	Vec2f c[] = {Vec2f(19.85, 12.45), Vec2f(18, 11.1), Vec2f(15.8, 10.3), Vec2f(13.55, 10), Vec2f(11.35, 10.3), Vec2f(9.2, 11.1), Vec2f(7.35, 12.45), Vec2f(5.85, 14.15), Vec2f(4.8, 16.2), Vec2f(4.2, 18.4), Vec2f(4.2, 20.65), Vec2f(4.75, 22.9), Vec2f(5.8, 24.95), Vec2f(7.3, 26.7), Vec2f(9.15, 28.05), Vec2f(11.35, 28.85), Vec2f(13.55, 29.1), Vec2f(15.9, 28.85), Vec2f(18, 28.05), Vec2f(19.9, 26.7) };
	C = std::vector<Vec2f>( c, c+(sizeof(c)/sizeof(c[0])) );

	Vec2f d[] = {Vec2f(4.8, 10.1), Vec2f(4.8, 12.5), Vec2f(4.8, 14.8), Vec2f(4.8, 17.2), Vec2f(4.8, 19.55), Vec2f(4.8, 21.9), Vec2f(4.8, 24.25), Vec2f(4.8, 26.65), Vec2f(4.8, 29), Vec2f(7, 29), Vec2f(9.25, 29), Vec2f(11.55, 28.7), Vec2f(13.7, 27.9), Vec2f(15.65, 26.6), Vec2f(17.15, 24.85), Vec2f(18.3, 22.85), Vec2f(18.85, 20.65), Vec2f(18.85, 18.35), Vec2f(18.25, 16.15), Vec2f(17.15, 14.15), Vec2f(15.6, 12.5), Vec2f(13.7, 11.15), Vec2f(11.55, 10.35), Vec2f(9.25, 10.1), Vec2f(7, 10.1) };
	D = std::vector<Vec2f>( d, d+(sizeof(d)/sizeof(d[0])) );

	Vec2f e[] = {Vec2f(4.8, 10.1), Vec2f(4.8, 12.5), Vec2f(4.8, 14.8), Vec2f(4.8, 17.2), Vec2f(4.8, 19.55), Vec2f(4.8, 21.9), Vec2f(4.8, 24.25), Vec2f(4.8, 26.65), Vec2f(4.8, 29), Vec2f(7, 10.1), Vec2f(9.2, 10.1), Vec2f(11.4, 10.1), Vec2f(13.6, 10.1), Vec2f(15.8, 10.1), Vec2f(6.95, 19.55), Vec2f(9.05, 19.55), Vec2f(11.25, 19.55), Vec2f(13.35, 19.55), Vec2f(15.5, 19.55), Vec2f(7, 29), Vec2f(9.2, 29), Vec2f(11.4, 29), Vec2f(13.6, 29), Vec2f(15.8, 29) };
	E = std::vector<Vec2f>( e, e+(sizeof(e)/sizeof(e[0])) );

	Vec2f f[] = {Vec2f(4.8, 10.1), Vec2f(4.8, 12.5), Vec2f(4.8, 14.8), Vec2f(4.8, 17.2), Vec2f(4.8, 19.55), Vec2f(4.8, 21.9), Vec2f(4.8, 24.25), Vec2f(4.8, 26.65), Vec2f(4.8, 29), Vec2f(7, 10.1), Vec2f(9.2, 10.1), Vec2f(11.4, 10.1), Vec2f(13.6, 10.1), Vec2f(15.8, 10.1), Vec2f(6.95, 19.55), Vec2f(9.05, 19.55), Vec2f(11.25, 19.55), Vec2f(13.35, 19.55), Vec2f(15.5, 19.55) };
	F = std::vector<Vec2f>( f, f+(sizeof(f)/sizeof(f[0])) );

	Vec2f g[] = {Vec2f(19.8, 12.4), Vec2f(17.95, 11.05), Vec2f(15.8, 10.25), Vec2f(13.55, 10), Vec2f(11.35, 10.25), Vec2f(9.2, 11.05), Vec2f(7.3, 12.4), Vec2f(5.8, 14.1), Vec2f(4.7, 16.15), Vec2f(4.2, 18.35), Vec2f(4.2, 20.65), Vec2f(4.7, 22.85), Vec2f(5.8, 24.85), Vec2f(7.25, 26.65), Vec2f(9.15, 27.95), Vec2f(11.25, 28.8), Vec2f(13.55, 29.1), Vec2f(15.85, 28.75), Vec2f(18, 27.9), Vec2f(19.85, 26.6), Vec2f(19.85, 24.25), Vec2f(19.85, 21.9), Vec2f(19.85, 19.55), Vec2f(17.45, 19.55), Vec2f(15.15, 19.55), Vec2f(12.75, 19.55) };
	G = std::vector<Vec2f>( g, g+(sizeof(g)/sizeof(g[0])) );

	Vec2f h[] = {Vec2f(4.8, 10.1), Vec2f(4.8, 12.5), Vec2f(4.8, 14.8), Vec2f(4.8, 17.2), Vec2f(4.8, 19.55), Vec2f(4.8, 21.9), Vec2f(4.8, 24.25), Vec2f(4.8, 26.65), Vec2f(4.8, 29), Vec2f(7.1, 19.55), Vec2f(9.4, 19.55), Vec2f(11.75, 19.55), Vec2f(14.1, 19.55), Vec2f(16.45, 19.55), Vec2f(18.75, 10.1), Vec2f(18.75, 12.5), Vec2f(18.75, 14.8), Vec2f(18.75, 17.2), Vec2f(18.75, 19.55), Vec2f(18.75, 21.9), Vec2f(18.75, 24.25), Vec2f(18.75, 26.65), Vec2f(18.75, 29) };
	H = std::vector<Vec2f>( h, h+(sizeof(h)/sizeof(h[0])) );

	Vec2f i[] = {Vec2f(4.35, 10.15), Vec2f(6.55, 10.15), Vec2f(8.75, 10.15), Vec2f(10.9, 10.15), Vec2f(7.65, 12.3), Vec2f(7.65, 14.7), Vec2f(7.65, 17.15), Vec2f(7.65, 19.55), Vec2f(7.65, 22), Vec2f(7.65, 24.4), Vec2f(7.65, 26.85), Vec2f(4.35, 29), Vec2f(6.55, 29), Vec2f(8.75, 29), Vec2f(10.9, 29) };
	I = std::vector<Vec2f>( i, i+(sizeof(i)/sizeof(i[0])) );

	Vec2f j[] = {Vec2f(6.1, 10.1), Vec2f(8.3, 10.1), Vec2f(10.5, 10.1), Vec2f(12.7, 10.1), Vec2f(12.7, 12.5), Vec2f(12.7, 14.8), Vec2f(12.7, 17.2), Vec2f(12.7, 19.55), Vec2f(12.7, 21.9), Vec2f(12.7, 24.25), Vec2f(12.3, 26.5), Vec2f(11, 28.3), Vec2f(8.95, 29.1), Vec2f(6.7, 29.05), Vec2f(4.8, 27.9), Vec2f(3.5, 26.1) };
	J = std::vector<Vec2f>( j, j+(sizeof(j)/sizeof(j[0])) );

	Vec2f k[] = {Vec2f(4.8, 10.1), Vec2f(4.8, 12.5), Vec2f(4.8, 14.8), Vec2f(4.8, 17.2), Vec2f(4.8, 19.55), Vec2f(4.8, 21.9), Vec2f(4.8, 24.25), Vec2f(4.8, 26.65), Vec2f(4.8, 29), Vec2f(7, 19.55), Vec2f(8.65, 17.95), Vec2f(10.35, 16.35), Vec2f(12.05, 14.8), Vec2f(13.75, 13.2), Vec2f(15.5, 11.65), Vec2f(17.2, 10.1), Vec2f(8.65, 21.1), Vec2f(10.35, 22.65), Vec2f(12.05, 24.25), Vec2f(13.75, 25.8), Vec2f(15.5, 27.4), Vec2f(17.2, 29) };
	K = std::vector<Vec2f>( k, k+(sizeof(k)/sizeof(k[0])) );

	Vec2f l[] = {Vec2f(4.8, 10.1), Vec2f(4.8, 12.5), Vec2f(4.8, 14.8), Vec2f(4.8, 17.2), Vec2f(4.8, 19.55), Vec2f(4.8, 21.9), Vec2f(4.8, 24.25), Vec2f(4.8, 26.65), Vec2f(4.8, 29), Vec2f(7, 29), Vec2f(9.2, 29), Vec2f(11.4, 29), Vec2f(13.6, 29), Vec2f(15.8, 29) };
	L = std::vector<Vec2f>( l, l+(sizeof(l)/sizeof(l[0])) );

	Vec2f m[] = {Vec2f(4.85, 10.1), Vec2f(4.75, 12.35), Vec2f(4.85, 14.8), Vec2f(4.85, 17.2), Vec2f(4.85, 19.55), Vec2f(4.85, 21.9), Vec2f(4.85, 24.3), Vec2f(4.85, 26.65), Vec2f(4.85, 29), Vec2f(6.4, 12.05), Vec2f(7.35, 13.95), Vec2f(8.6, 15.95), Vec2f(9.9, 17.9), Vec2f(11.15, 19.85), Vec2f(12.45, 21.75), Vec2f(13.7, 23.75), Vec2f(14.95, 21.75), Vec2f(16.25, 19.85), Vec2f(17.5, 17.9), Vec2f(18.75, 15.95), Vec2f(20.05, 14), Vec2f(21.05, 11.8), Vec2f(22.6, 10.1), Vec2f(22.75, 12.45), Vec2f(22.6, 14.8), Vec2f(22.6, 17.2), Vec2f(22.6, 19.55), Vec2f(22.6, 21.9), Vec2f(22.6, 24.3), Vec2f(22.6, 26.65), Vec2f(22.6, 29) };
	M = std::vector<Vec2f>( m, m+(sizeof(m)/sizeof(m[0])) );

	Vec2f n[] = {Vec2f(4.8, 10.15), Vec2f(4.65, 12.25), Vec2f(4.85, 14.55), Vec2f(4.85, 16.9), Vec2f(4.85, 19.35), Vec2f(4.85, 21.75), Vec2f(4.85, 24.15), Vec2f(4.85, 26.55), Vec2f(4.85, 29), Vec2f(6.35, 11.95), Vec2f(7.65, 13.75), Vec2f(9.15, 15.7), Vec2f(10.6, 17.65), Vec2f(12.15, 19.55), Vec2f(13.6, 21.45), Vec2f(15.1, 23.4), Vec2f(16.6, 25.3), Vec2f(17.8, 27.2), Vec2f(19.45, 29), Vec2f(19.55, 26.8), Vec2f(19.4, 24.6), Vec2f(19.4, 22.15), Vec2f(19.4, 19.75), Vec2f(19.4, 17.35), Vec2f(19.4, 14.9), Vec2f(19.4, 12.55), Vec2f(19.4, 10.15) };
	N = std::vector<Vec2f>( n, n+(sizeof(n)/sizeof(n[0])) );

	Vec2f o[] = {Vec2f(13.55, 10), Vec2f(15.8, 10.3), Vec2f(18, 11.05), Vec2f(19.8, 12.4), Vec2f(21.35, 14.1), Vec2f(22.4, 16.15), Vec2f(22.95, 18.35), Vec2f(22.95, 20.65), Vec2f(22.4, 22.85), Vec2f(21.4, 24.9), Vec2f(19.85, 26.65), Vec2f(18, 27.95), Vec2f(15.85, 28.8), Vec2f(13.55, 29.1), Vec2f(11.3, 28.8), Vec2f(9.15, 27.95), Vec2f(7.25, 26.65), Vec2f(5.8, 24.9), Vec2f(4.7, 22.85), Vec2f(4.2, 20.65), Vec2f(4.2, 18.35), Vec2f(4.75, 16.15), Vec2f(5.8, 14.1), Vec2f(7.3, 12.4), Vec2f(9.2, 11.05), Vec2f(11.35, 10.3) };
	O = std::vector<Vec2f>( o, o+(sizeof(o)/sizeof(o[0])) );

	Vec2f p[] = {Vec2f(4.8, 10.1), Vec2f(4.8, 12.5), Vec2f(4.8, 14.85), Vec2f(4.8, 17.2), Vec2f(4.8, 19.6), Vec2f(4.8, 21.9), Vec2f(4.8, 24.3), Vec2f(4.8, 26.65), Vec2f(4.8, 29), Vec2f(7, 10.1), Vec2f(9.2, 10.1), Vec2f(11.45, 10.1), Vec2f(13.75, 10.2), Vec2f(15.95, 11), Vec2f(17.5, 12.75), Vec2f(18.45, 14.9), Vec2f(18.4, 17.2), Vec2f(17.45, 19.35), Vec2f(15.85, 21.05), Vec2f(13.7, 21.8), Vec2f(11.45, 21.9), Vec2f(9.2, 21.9), Vec2f(7, 21.9) };
	P = std::vector<Vec2f>( p, p+(sizeof(p)/sizeof(p[0])) );

	Vec2f q[] = {Vec2f(16.15, 28.35), Vec2f(18.3, 27.4), Vec2f(20.15, 26), Vec2f(21.6, 24.15), Vec2f(22.6, 22), Vec2f(22.95, 19.65), Vec2f(22.75, 17.3), Vec2f(22, 15.1), Vec2f(20.7, 13.1), Vec2f(18.95, 11.55), Vec2f(16.85, 10.45), Vec2f(14.55, 9.9), Vec2f(12.2, 10), Vec2f(9.9, 10.6), Vec2f(7.85, 11.75), Vec2f(6.2, 13.4), Vec2f(4.95, 15.4), Vec2f(4.3, 17.7), Vec2f(4.2, 20.05), Vec2f(4.65, 22.35), Vec2f(5.7, 24.45), Vec2f(7.25, 26.3), Vec2f(9.15, 27.6), Vec2f(11.35, 28.6), Vec2f(13.5, 29.55), Vec2f(15.6, 30.55), Vec2f(17.75, 31.5), Vec2f(19.95, 32.55), Vec2f(22.05, 33.5) };
	Q = std::vector<Vec2f>( q, q+(sizeof(q)/sizeof(q[0])) );

	Vec2f r[] = {Vec2f(4.8, 10.1), Vec2f(4.8, 12.5), Vec2f(4.8, 14.85), Vec2f(4.8, 17.2), Vec2f(4.8, 19.6), Vec2f(4.8, 21.9), Vec2f(4.8, 24.3), Vec2f(4.8, 26.65), Vec2f(4.8, 29), Vec2f(7, 10.1), Vec2f(9.2, 10.1), Vec2f(11.45, 10.1), Vec2f(13.75, 10.2), Vec2f(15.95, 11), Vec2f(17.5, 12.75), Vec2f(18.4, 14.9), Vec2f(18.35, 17.2), Vec2f(17.45, 19.35), Vec2f(15.9, 21), Vec2f(13.7, 21.8), Vec2f(11.45, 21.9), Vec2f(9.2, 21.9), Vec2f(7, 21.9), Vec2f(12.65, 23.85), Vec2f(14.25, 25.55), Vec2f(15.85, 27.3), Vec2f(17.4, 29) };
	R = std::vector<Vec2f>( r, r+(sizeof(r)/sizeof(r[0])) );

	Vec2f s[] = {Vec2f(15.85, 12.55), Vec2f(14, 11.1), Vec2f(11.9, 10.2), Vec2f(9.65, 10.05), Vec2f(7.4, 10.5), Vec2f(5.4, 11.6), Vec2f(4.15, 13.55), Vec2f(4.4, 15.85), Vec2f(5.8, 17.65), Vec2f(7.85, 18.65), Vec2f(10, 19.25), Vec2f(12.25, 19.8), Vec2f(14.35, 20.65), Vec2f(16.2, 22.15), Vec2f(16.65, 24.35), Vec2f(15.95, 26.5), Vec2f(14.3, 28.1), Vec2f(12.2, 28.95), Vec2f(9.9, 29.1), Vec2f(7.65, 28.75), Vec2f(5.65, 27.7), Vec2f(4, 26.1) };
	S = std::vector<Vec2f>( s, s+(sizeof(s)/sizeof(s[0])) );

	Vec2f t[] = {Vec2f(3.45, 10.1), Vec2f(5.7, 10.1), Vec2f(8, 10.1), Vec2f(10.3, 10.1), Vec2f(12.6, 10.1), Vec2f(14.85, 10.1), Vec2f(17.15, 10.1), Vec2f(10.3, 12.5), Vec2f(10.3, 14.8), Vec2f(10.3, 17.2), Vec2f(10.3, 19.55), Vec2f(10.3, 21.9), Vec2f(10.3, 24.25), Vec2f(10.3, 26.65), Vec2f(10.3, 29) };
	T = std::vector<Vec2f>( t, t+(sizeof(t)/sizeof(t[0])) );

	Vec2f u[] = {Vec2f(4.65, 10.1), Vec2f(4.65, 12.5), Vec2f(4.65, 14.8), Vec2f(4.65, 17.2), Vec2f(4.65, 19.55), Vec2f(4.65, 21.9), Vec2f(4.95, 24.15), Vec2f(6, 26.3), Vec2f(7.75, 27.85), Vec2f(9.85, 28.8), Vec2f(12.15, 29.1), Vec2f(14.4, 28.8), Vec2f(16.5, 27.85), Vec2f(18.3, 26.3), Vec2f(19.3, 24.15), Vec2f(19.65, 21.9), Vec2f(19.65, 19.55), Vec2f(19.65, 17.2), Vec2f(19.65, 14.8), Vec2f(19.65, 12.5), Vec2f(19.65, 10.1) };
	U = std::vector<Vec2f>( u, u+(sizeof(u)/sizeof(u[0])) );

	Vec2f v[] = {Vec2f(3.6, 10.1), Vec2f(4.45, 12.2), Vec2f(5.35, 14.25), Vec2f(6.25, 16.35), Vec2f(7.1, 18.45), Vec2f(8, 20.55), Vec2f(8.9, 22.7), Vec2f(9.75, 24.85), Vec2f(10.45, 27), Vec2f(11.55, 29), Vec2f(12.6, 27), Vec2f(13.4, 24.85), Vec2f(14.2, 22.7), Vec2f(15.1, 20.55), Vec2f(16, 18.45), Vec2f(16.85, 16.35), Vec2f(17.75, 14.25), Vec2f(18.65, 12.2), Vec2f(19.5, 10.1) };
	V = std::vector<Vec2f>( v, v+(sizeof(v)/sizeof(v[0])) );

	Vec2f w[] = {Vec2f(3.9, 10.15), Vec2f(4.5, 12.5), Vec2f(5.1, 14.9), Vec2f(5.7, 17.3), Vec2f(6.3, 19.7), Vec2f(6.9, 22.1), Vec2f(7.5, 24.5), Vec2f(8, 26.85), Vec2f(8.85, 29), Vec2f(9.85, 26.85), Vec2f(10.55, 24.75), Vec2f(11.3, 22.65), Vec2f(12, 20.55), Vec2f(12.7, 18.45), Vec2f(13.4, 16.4), Vec2f(14.15, 14.3), Vec2f(14.85, 12.2), Vec2f(15.8, 10.15), Vec2f(16.75, 12.2), Vec2f(17.45, 14.3), Vec2f(18.15, 16.4), Vec2f(18.85, 18.45), Vec2f(19.6, 20.55), Vec2f(20.3, 22.65), Vec2f(21, 24.75), Vec2f(21.75, 26.85), Vec2f(22.7, 29), Vec2f(23.6, 26.85), Vec2f(24.1, 24.5), Vec2f(24.7, 22.1), Vec2f(25.3, 19.7), Vec2f(25.9, 17.3), Vec2f(26.5, 14.9), Vec2f(27.1, 12.5), Vec2f(27.7, 10.15) };
	W = std::vector<Vec2f>( w, w+(sizeof(w)/sizeof(w[0])) );

	Vec2f x[] = {Vec2f(3.95, 10.1), Vec2f(5.3, 11.95), Vec2f(6.75, 13.85), Vec2f(8.15, 15.75), Vec2f(9.55, 17.65), Vec2f(10.95, 19.55), Vec2f(12.35, 21.45), Vec2f(13.75, 23.35), Vec2f(15.2, 25.2), Vec2f(16.6, 27.1), Vec2f(18, 29), Vec2f(3.95, 29), Vec2f(5.35, 27.1), Vec2f(6.75, 25.2), Vec2f(8.15, 23.35), Vec2f(9.55, 21.45), Vec2f(12.35, 17.65), Vec2f(13.75, 15.75), Vec2f(15.2, 13.85), Vec2f(16.6, 11.95), Vec2f(18, 10.1) };
	X = std::vector<Vec2f>( x, x+(sizeof(x)/sizeof(x[0])) );

	Vec2f y[] = {Vec2f(3.6, 10.1), Vec2f(4.9, 11.8), Vec2f(6.25, 13.5), Vec2f(7.6, 15.25), Vec2f(8.9, 16.9), Vec2f(10.15, 18.6), Vec2f(11.5, 20.25), Vec2f(11.5, 22.4), Vec2f(11.5, 24.65), Vec2f(11.5, 26.8), Vec2f(11.5, 29), Vec2f(12.8, 18.6), Vec2f(14.1, 16.9), Vec2f(15.4, 15.25), Vec2f(16.7, 13.5), Vec2f(18.05, 11.8), Vec2f(19.4, 10.1) };
	Y = std::vector<Vec2f>( y, y+(sizeof(y)/sizeof(y[0])) );

	Vec2f z[] = {Vec2f(4.2, 10.1), Vec2f(6.4, 10.1), Vec2f(8.6, 10.1), Vec2f(10.8, 10.1), Vec2f(13, 10.1), Vec2f(15.2, 10.05), Vec2f(17.4, 10.1), Vec2f(16.2, 11.9), Vec2f(15, 13.55), Vec2f(13.8, 15.3), Vec2f(12.55, 17), Vec2f(11.35, 18.7), Vec2f(10.2, 20.4), Vec2f(8.95, 22.15), Vec2f(7.8, 23.85), Vec2f(6.6, 25.55), Vec2f(5.35, 27.25), Vec2f(4.2, 29), Vec2f(6.4, 29.05), Vec2f(8.6, 29), Vec2f(10.8, 29), Vec2f(13, 29), Vec2f(15.2, 29), Vec2f(17.4, 29) };
	Z = std::vector<Vec2f>( z, z+(sizeof(z)/sizeof(z[0])) );
	
	Vec2f zero[] = { Vec2f(10.6,10),Vec2f(8.45,10.55),Vec2f(6.7,11.95),Vec2f(5.45,13.9),Vec2f(4.75,16.05),Vec2f(4.5,18.4),Vec2f(4.5,20.65),Vec2f(4.8,22.9),Vec2f(5.6,25.1),Vec2f(6.8,27),Vec2f(8.5,28.45),Vec2f(10.6,29.1),Vec2f(12.8,28.45),Vec2f(14.5,27),Vec2f(15.7,25.1),Vec2f(16.45,22.9),Vec2f(16.8,20.65),Vec2f(16.85,18.4),Vec2f(16.5,16.05),Vec2f(15.8,13.9),Vec2f(14.6,11.95),Vec2f(12.8,10.55) };
	ZERO = std::vector<Vec2f>( zero, zero+(sizeof(zero)/sizeof(zero[0])) );

	Vec2f one[] = { Vec2f(3.9,12.55),Vec2f(5.85,11.3),Vec2f(7.8,10.1),Vec2f(7.8,12.5),Vec2f(7.8,14.9),Vec2f(7.8,17.25),Vec2f(7.8,19.6),Vec2f(7.8,21.95),Vec2f(7.8,24.35),Vec2f(7.8,26.65),Vec2f(7.8,29) };
	ONE = std::vector<Vec2f>( one, one+(sizeof(one)/sizeof(one[0])) );

	Vec2f two[] = { Vec2f(4.3,13.8),Vec2f(5.5,12),Vec2f(7.2,10.7),Vec2f(9.3,10.05),Vec2f(11.45,10.05),Vec2f(13.5,10.75),Vec2f(15.1,12.2),Vec2f(15.65,14.3),Vec2f(15.35,16.45),Vec2f(14.1,18.25),Vec2f(12.35,19.5),Vec2f(10.4,20.55),Vec2f(8.55,21.75),Vec2f(6.85,23.1),Vec2f(5.6,24.9),Vec2f(4.75,26.9),Vec2f(4.65,29.05),Vec2f(6.8,29),Vec2f(9.05,29),Vec2f(11.35,29),Vec2f(13.55,29),Vec2f(15.75,29) };
	TWO = std::vector<Vec2f>( two, two+(sizeof(two)/sizeof(two[0])) );
	
	Vec2f three[] = { Vec2f(4.25,13.3),Vec2f(5.45,11.55),Vec2f(7.25,10.4),Vec2f(9.4,10.05),Vec2f(11.5,10.65),Vec2f(13.05,12.15),Vec2f(13.65,14.25),Vec2f(13.25,16.35),Vec2f(11.9,18),Vec2f(10.05,19.05),Vec2f(7.95,19.05),Vec2f(11.95,19.9),Vec2f(13.7,21.2),Vec2f(14.5,23.15),Vec2f(14.35,25.25),Vec2f(13.4,27.1),Vec2f(11.75,28.45),Vec2f(9.65,29.05),Vec2f(7.5,28.9),Vec2f(5.6,28),Vec2f(4,26.55) };
	THREE = std::vector<Vec2f>( three, three+(sizeof(three)/sizeof(three[0])) );

	Vec2f four[] = { Vec2f(15.25,10.1),Vec2f(15.25,12.2),Vec2f(13.7,11.85),Vec2f(12.45,13.65),Vec2f(11,15.45),Vec2f(9.6,17.25),Vec2f(8.15,19.05),Vec2f(6.7,20.85),Vec2f(5.3,22.6),Vec2f(4,24.3),Vec2f(6.15,24.3),Vec2f(8.4,24.25),Vec2f(10.6,24.25),Vec2f(12.9,24.25),Vec2f(15.2,24.2),Vec2f(15.2,14.65),Vec2f(15.2,17.05),Vec2f(15.2,19.45),Vec2f(15.2,21.85),Vec2f(17.45,24.25),Vec2f(15.2,26.6),Vec2f(15.2,29) };
	FOUR = std::vector<Vec2f>( four, four+(sizeof(four)/sizeof(four[0])) );

	Vec2f five[] = { Vec2f(12.8,10.05),Vec2f(10.6,10.05),Vec2f(8.45,10.05),Vec2f(6.3,10.05),Vec2f(5.9,12.2),Vec2f(5.6,14.45),Vec2f(5.2,16.7),Vec2f(4.9,18.9),Vec2f(6.9,18.05),Vec2f(9.05,17.75),Vec2f(11.2,18),Vec2f(13,19.1),Vec2f(14.35,20.85),Vec2f(14.95,22.85),Vec2f(14.8,25.05),Vec2f(13.95,27),Vec2f(12.3,28.4),Vec2f(10.25,29),Vec2f(8.1,28.95),Vec2f(6.1,28.1),Vec2f(4.6,26.65) };
	FIVE = std::vector<Vec2f>( five, five+(sizeof(five)/sizeof(five[0])) );

	Vec2f six[] = { Vec2f(13,9.95),Vec2f(11.15,11.1),Vec2f(9.5,12.5),Vec2f(8,14.05),Vec2f(6.7,15.75),Vec2f(5.6,17.6),Vec2f(4.95,19.7),Vec2f(4.6,21.8),Vec2f(4.7,23.95),Vec2f(5.35,26),Vec2f(6.6,27.75),Vec2f(8.45,28.85),Vec2f(10.55,29.2),Vec2f(12.7,28.7),Vec2f(14.4,27.5),Vec2f(15.65,25.75),Vec2f(16.1,23.6),Vec2f(15.85,21.5),Vec2f(14.7,19.65),Vec2f(12.95,18.4),Vec2f(10.9,17.85),Vec2f(8.8,18.2),Vec2f(6.95,19.2) };
	SIX = std::vector<Vec2f>( six, six+(sizeof(six)/sizeof(six[0])) );

	Vec2f seven[] = { Vec2f(4.2,10.15),Vec2f(6.45,10.15),Vec2f(8.65,10.15),Vec2f(10.9,10.15),Vec2f(13.15,10.15),Vec2f(15.4,10.15),Vec2f(14.2,12.1),Vec2f(12.95,14.05),Vec2f(11.75,16.05),Vec2f(10.55,18.15),Vec2f(9.5,20.25),Vec2f(8.45,22.35),Vec2f(7.55,24.55),Vec2f(6.6,26.75),Vec2f(5.95,28.95) };
	SEVEN = std::vector<Vec2f>( seven, seven+(sizeof(seven)/sizeof(seven[0])) );

	Vec2f eight[] = { Vec2f(8.65,10.05),Vec2f(6.65,11.2),Vec2f(5.4,13.15),Vec2f(5.1,15.4),Vec2f(5.95,17.55),Vec2f(7.45,19.3),Vec2f(5.65,20.8),Vec2f(4.65,22.9),Vec2f(4.65,25.2),Vec2f(5.65,27.2),Vec2f(7.45,28.7),Vec2f(9.8,29.05),Vec2f(12.05,28.7),Vec2f(13.9,27.2),Vec2f(14.9,25.2),Vec2f(14.9,22.9),Vec2f(13.9,20.8),Vec2f(12.05,19.35),Vec2f(9.8,19.2),Vec2f(13.55,17.55),Vec2f(14.45,15.4),Vec2f(14.15,13.15),Vec2f(12.9,11.2),Vec2f(10.85,10.05) };
	EIGHT = std::vector<Vec2f>( eight, eight+(sizeof(eight)/sizeof(eight[0])) );

	Vec2f nine[] = { Vec2f(7.35,29.05),Vec2f(9.35,27.85),Vec2f(11.1,26.3),Vec2f(12.6,24.55),Vec2f(13.85,22.55),Vec2f(14.65,20.35),Vec2f(15.3,18.2),Vec2f(15.6,15.9),Vec2f(15.15,13.65),Vec2f(13.95,11.8),Vec2f(12.1,10.5),Vec2f(9.9,10.1),Vec2f(7.7,10.5),Vec2f(5.85,11.8),Vec2f(4.6,13.65),Vec2f(4.15,15.9),Vec2f(4.6,18.15),Vec2f(5.9,20),Vec2f(7.95,21.1),Vec2f(10.2,21.45),Vec2f(12.45,20.9) };
	NINE = std::vector<Vec2f>( nine, nine+(sizeof(nine)/sizeof(nine[0])) );

	Vec2f fullstop[] = { Vec2f(3.95,28.95) };
	FULL_STOP = std::vector<Vec2f>( fullstop, fullstop+(sizeof(fullstop)/sizeof(fullstop[0])) );

	Vec2f greaterthan[] = { Vec2f(4.1,11),Vec2f(5.75,12.45),Vec2f(7.35,13.85),Vec2f(9,15.2),Vec2f(10.65,16.6),Vec2f(12.25,18),Vec2f(13.9,19.4),Vec2f(12.25,20.75),Vec2f(10.65,22.1),Vec2f(9,23.5),Vec2f(7.3,24.9),Vec2f(5.7,26.25),Vec2f(4.05,27.6) };
	GREATER_THAN = std::vector<Vec2f>( greaterthan, greaterthan+(sizeof(greaterthan)/sizeof(greaterthan[0])) );

	Vec2f lessthan[] = { Vec2f(13.95,11.05),Vec2f(12.25,12.45),Vec2f(10.65,13.8),Vec2f(9,15.2),Vec2f(7.35,16.6),Vec2f(5.75,18),Vec2f(4.1,19.35),Vec2f(5.75,20.75),Vec2f(7.35,22.1),Vec2f(9,23.5),Vec2f(10.65,24.9),Vec2f(12.25,26.3),Vec2f(13.95,27.65) };
	LESS_THAN = std::vector<Vec2f>( lessthan, lessthan+(sizeof(lessthan)/sizeof(lessthan[0])) );

	Vec2f questionmark[] = { Vec2f(3.7,12.05),Vec2f(5.5,10.55),Vec2f(7.8,10),Vec2f(10.2,10.1),Vec2f(12.25,11.15),Vec2f(13.4,13.35),Vec2f(13.45,15.7),Vec2f(12.4,17.85),Vec2f(10.55,19.35),Vec2f(8.4,20.35),Vec2f(8.4,26.5),Vec2f(8.4,28.9) };
	QUESTION_MARK = std::vector<Vec2f>( questionmark, questionmark+(sizeof(questionmark)/sizeof(questionmark[0])) );

	Vec2f exclamationmark[] = { Vec2f(4.7,9.55),Vec2f(4.7,11.7),Vec2f(4.7,13.85),Vec2f(4.7,16.05),Vec2f(4.7,18.2),Vec2f(4.7,20.35),Vec2f(4.7,26.75),Vec2f(4.7,28.95) };
	EXCLAMATION_MARK = std::vector<Vec2f>( exclamationmark, exclamationmark+(sizeof(exclamationmark)/sizeof(exclamationmark[0])) );

	Vec2f pound[] = { Vec2f(15.75,12.2),Vec2f(13.95,10.75),Vec2f(11.75,10.05),Vec2f(9.45,10.15),Vec2f(7.3,11.1),Vec2f(5.95,13),Vec2f(5.6,15.25),Vec2f(5.9,17.55),Vec2f(6.45,19.8),Vec2f(6.9,22.1),Vec2f(6.75,24.4),Vec2f(6.25,26.7),Vec2f(5.4,28.9),Vec2f(7.6,28.9),Vec2f(9.8,28.9),Vec2f(12,28.9),Vec2f(14.2,28.9),Vec2f(16.4,28.9),Vec2f(4.1,19.8),Vec2f(8.75,19.8),Vec2f(11.05,19.8),Vec2f(13.4,19.8) };
	POUND = std::vector<Vec2f>( pound, pound+(sizeof(pound)/sizeof(pound[0])) );

	Vec2f euro[] = { Vec2f(18.35,11.95),Vec2f(16.65,10.7),Vec2f(14.6,10.05),Vec2f(12.45,9.95),Vec2f(10.35,10.35),Vec2f(8.5,11.45),Vec2f(7.25,13.2),Vec2f(6.55,15.25),Vec2f(6.25,17.35),Vec2f(6.3,19.55),Vec2f(6.3,21.65),Vec2f(6.55,23.85),Vec2f(7.3,25.85),Vec2f(8.6,27.55),Vec2f(10.45,28.65),Vec2f(12.55,29),Vec2f(14.75,28.9),Vec2f(16.8,28.3),Vec2f(18.55,27.1),Vec2f(4.15,17.35),Vec2f(8.4,17.35),Vec2f(10.5,17.35),Vec2f(12.55,17.35),Vec2f(6.25,21.65),Vec2f(4.15,21.65),Vec2f(8.4,21.65),Vec2f(10.5,21.65),Vec2f(12.55,21.65) };
	EURO = std::vector<Vec2f>( euro, euro+(sizeof(euro)/sizeof(euro[0])) );

	Vec2f percentage[] = { Vec2f(7.2,10),Vec2f(9.3,10.7),Vec2f(10.4,12.6),Vec2f(10.35,14.8),Vec2f(9.3,16.7),Vec2f(7.2,17.4),Vec2f(5.05,16.7),Vec2f(4,14.8),Vec2f(4,12.6),Vec2f(5.05,10.7),Vec2f(16.7,21.45),Vec2f(18.8,22.15),Vec2f(19.9,24.05),Vec2f(19.85,26.25),Vec2f(18.8,28.15),Vec2f(16.7,28.85),Vec2f(14.55,28.15),Vec2f(13.5,26.25),Vec2f(13.5,24.05),Vec2f(14.55,22.15),Vec2f(6.1,26.15),Vec2f(7.6,24.4),Vec2f(9.1,22.7),Vec2f(10.6,21),Vec2f(12.05,19.3),Vec2f(13.55,17.6),Vec2f(15.05,15.85),Vec2f(16.55,14.15),Vec2f(18.05,12.45) };
	PERCENTAGE = std::vector<Vec2f>( percentage, percentage+(sizeof(percentage)/sizeof(percentage[0])) );

	Vec2f ampersand[] = { Vec2f(17.05,28.85),Vec2f(15.45,27.2),Vec2f(13.8,25.5),Vec2f(12.25,23.85),Vec2f(10.6,22.15),Vec2f(9,20.5),Vec2f(7.4,18.8),Vec2f(5.85,17.2),Vec2f(4.85,15.05),Vec2f(5,12.8),Vec2f(6.35,10.9),Vec2f(8.5,10.05),Vec2f(10.85,10.2),Vec2f(12.8,11.45),Vec2f(13.7,13.6),Vec2f(13.5,15.9),Vec2f(12.05,17.7),Vec2f(9.85,18.5),Vec2f(5.85,20.6),Vec2f(4.25,22.25),Vec2f(3.65,24.45),Vec2f(4.25,26.7),Vec2f(6,28.25),Vec2f(8.25,28.9),Vec2f(10.5,28.6),Vec2f(12.35,27.25),Vec2f(15.35,23.8),Vec2f(16.55,21.85),Vec2f(17.65,19.8) };	
	AMPERSAND = std::vector<Vec2f>( ampersand, ampersand+(sizeof(ampersand)/sizeof(ampersand[0])) );

	Vec2f circumflex[] = { Vec2f(4.05,19.6),Vec2f(5,17.65),Vec2f(5.9,15.75),Vec2f(6.9,13.8),Vec2f(7.75,11.9),Vec2f(8.75,9.95),Vec2f(9.7,11.9),Vec2f(10.6,13.8),Vec2f(11.55,15.75),Vec2f(12.5,17.65),Vec2f(13.4,19.6) };
	CIRCUMFLEX = std::vector<Vec2f>( circumflex, circumflex+(sizeof(circumflex)/sizeof(circumflex[0])) );

	Vec2f atsymbol[] = { Vec2f(17.25,27),Vec2f(14.9,27.15),Vec2f(12.75,26.25),Vec2f(11.4,24.4),Vec2f(11.05,22.05),Vec2f(11.45,19.7),Vec2f(12.75,17.8),Vec2f(14.9,16.9),Vec2f(17.2,17.1),Vec2f(19.05,18.5),Vec2f(19.95,20.7),Vec2f(20.05,23.05),Vec2f(20.55,25.35),Vec2f(22.4,26.65),Vec2f(24.65,26),Vec2f(25.65,24),Vec2f(26,21.7),Vec2f(25.95,19.3),Vec2f(25.55,17),Vec2f(24.65,14.8),Vec2f(23.3,12.9),Vec2f(21.5,11.45),Vec2f(19.35,10.45),Vec2f(17.05,9.95),Vec2f(14.7,10),Vec2f(12.4,10.45),Vec2f(10.3,11.35),Vec2f(8.4,12.75),Vec2f(6.85,14.55),Vec2f(5.8,16.65),Vec2f(5.15,18.9),Vec2f(4.9,21.25),Vec2f(5,23.65),Vec2f(5.45,25.9),Vec2f(6.3,28.1),Vec2f(7.6,30.05),Vec2f(9.25,31.65),Vec2f(11.3,32.85),Vec2f(13.55,33.55),Vec2f(15.9,33.8),Vec2f(18.2,33.6),Vec2f(20.45,32.9) };
	AT_SYMBOL = std::vector<Vec2f>( atsymbol, atsymbol+(sizeof(atsymbol)/sizeof(atsymbol[0])) );

	Vec2f openbracket[] = { Vec2f(8.95,7.05),Vec2f(7.6,8.85),Vec2f(6.45,10.75),Vec2f(5.6,12.8),Vec2f(4.95,15),Vec2f(4.5,17.2),Vec2f(4.3,19.4),Vec2f(4.25,21.65),Vec2f(4.5,23.9),Vec2f(5,26.1),Vec2f(5.6,28.2),Vec2f(6.5,30.25),Vec2f(7.6,32.2),Vec2f(8.95,34.05) };
	OPEN_BRACKET = std::vector<Vec2f>( openbracket, openbracket+(sizeof(openbracket)/sizeof(openbracket[0])) );

	Vec2f closebracket[] = { Vec2f(3.85,7.05),Vec2f(5.2,8.95),Vec2f(6.3,10.85),Vec2f(7.2,12.95),Vec2f(7.85,15.05),Vec2f(8.3,17.25),Vec2f(8.5,19.5),Vec2f(8.55,21.75),Vec2f(8.3,23.95),Vec2f(7.85,26.15),Vec2f(7.2,28.3),Vec2f(6.35,30.35),Vec2f(5.2,32.3),Vec2f(3.85,34.1) };
	CLOSE_BRACKET = std::vector<Vec2f>( closebracket, closebracket+(sizeof(closebracket)/sizeof(closebracket[0])) );

	Vec2f plus[] = { Vec2f(10.75,12.7),Vec2f(10.75,14.95),Vec2f(10.75,17.15),Vec2f(10.75,19.35),Vec2f(10.75,21.5),Vec2f(10.75,23.7),Vec2f(10.75,25.9),Vec2f(4.15,19.3),Vec2f(6.35,19.3),Vec2f(8.55,19.3),Vec2f(12.9,19.3),Vec2f(15.1,19.3),Vec2f(17.3,19.3) };
	PLUS = std::vector<Vec2f>( plus, plus+(sizeof(plus)/sizeof(plus[0])) );

	Vec2f equals[] = { Vec2f(4.15,16.7),Vec2f(6.35,16.7),Vec2f(8.55,16.7),Vec2f(10.75,16.7),Vec2f(12.95,16.7),Vec2f(15.1,16.7),Vec2f(4.15,22),Vec2f(6.35,22),Vec2f(8.55,22),Vec2f(10.75,22),Vec2f(12.95,22),Vec2f(15.1,22) };
	EQUALS = std::vector<Vec2f>( equals, equals+(sizeof(equals)/sizeof(equals[0])) );

	Vec2f dash[] = { Vec2f(3.65,21.3),Vec2f(5.85,21.3),Vec2f(8.1,21.3) };
	DASH = std::vector<Vec2f>( dash, dash+(sizeof(dash)/sizeof(dash[0])) );

	Vec2f underscore[] = { Vec2f(2.9,32.15),Vec2f(5.1,32.15),Vec2f(7.3,32.15),Vec2f(9.5,32.15),Vec2f(11.7,32.15) };
	UNDERSCORE = std::vector<Vec2f>( underscore, underscore+(sizeof(underscore)/sizeof(underscore[0])) );

	Vec2f forwardslash[] = { Vec2f(11.05,9),Vec2f(10.25,11.05),Vec2f(9.4,13.15),Vec2f(8.6,15.25),Vec2f(7.75,17.3),Vec2f(6.95,19.45),Vec2f(6.1,21.5),Vec2f(5.25,23.6),Vec2f(4.45,25.7),Vec2f(3.65,27.75),Vec2f(2.8,29.85) };
	FORWARD_SLASH = std::vector<Vec2f>( forwardslash, forwardslash+(sizeof(forwardslash)/sizeof(forwardslash[0])) );

	Vec2f doublequote[] = { Vec2f(4.85,9.95),Vec2f(4.85,12.25),Vec2f(4.85,14.5),Vec2f(8.25,9.95),Vec2f(8.25,12.25),Vec2f(8.25,14.5) };
	DOUBLE_QUOTE = std::vector<Vec2f>( doublequote, doublequote+(sizeof(doublequote)/sizeof(doublequote[0])) );

	Vec2f singlequote[] = { Vec2f(4.85,9.95),Vec2f(4.85,12.25),Vec2f(4.85,14.5) };
	SINGLE_QUOTE = std::vector<Vec2f>( singlequote, singlequote+(sizeof(singlequote)/sizeof(singlequote[0])) );

	Vec2f colon[] = { Vec2f(4.25,16.2),Vec2f(4.25,28.8) };
	COLON = std::vector<Vec2f>( colon, colon+(sizeof(colon)/sizeof(colon[0])) );

	Vec2f semicolon[] = { Vec2f(4.3,16.2),Vec2f(4.35,28.9),Vec2f(4.35,31.05),Vec2f(3.15,32.85) };
	SEMI_COLON = std::vector<Vec2f>( semicolon, semicolon+(sizeof(semicolon)/sizeof(semicolon[0])) );

	Vec2f comma[] = { Vec2f(4.2,27.85),Vec2f(4.2,30),Vec2f(3,31.8) };
	COMMA = std::vector<Vec2f>( comma, comma+(sizeof(comma)/sizeof(comma[0])) );
	*/
}