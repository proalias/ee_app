#pragma once


class FireFlyWaveScheme {
 
public:

	FireFlyWaveScheme( std::string pkey, std::vector<int> pvalues )
	{
		key=pkey;
		values=pvalues;
	}
	//~FireFlyWaveScheme(void);


	std::string key;
	std::vector<int> values;
	

	/*
	 waveStartScheme : Object = {
	'01' : [ 2, 3 ], '10' : [ 2, 3 ], '23' : [ 0, 1 ],
	'32' : [ 0, 1 ],
	'02' : [ 1, 3, 7 ],
	'20' : [ 1, 3, 7 ],
	'03' : [ 1, 2, 5 ],
	'30' : [ 1, 2, 5 ],
	'31' : [ 0, 2, 4 ],
	'13' : [ 0, 2, 4 ],
	'12' : [ 0, 3, 6 ],
	'21' : [ 0, 3, 6 ],
	'0-1' : [ 1, 2, 3, 5, 7 ],
	'1-1' : [ 0, 2, 3, 4, 6 ],
	'2-1' : [ 0, 1, 3, 6, 7 ],
	'3-1' : [ 0, 1, 2, 4, 5 ]
	};
	*/

};