#ifndef TCoordinateH
#define TCoordinateH


class TCoordinate

{

private:

	inline void CartesianPolar(void);
	inline void PolarCartesian(void);

	double AngleValue;
	double LengthValue;
public:

	double x;
	double y;

	//-----------------------------------

	//«ØºcšçŠ¡

	TCoordinate(double xValue,double yValue);       //(X,Y)

	TCoordinate(double sita);

	TCoordinate();

	//žÑºcšçŠ¡

	~TCoordinate();


	//------------¹Bºâ€l­«žü--------------

	bool operator == (TCoordinate op2);

	TCoordinate operator + (TCoordinate op2);

	TCoordinate operator - (TCoordinate op2);



	TCoordinate operator << (double ds);

	TCoordinate operator >> (double ds);

	//---------- -Šš­û šçŠ¡--------------

	double	Angle();

	double	Length();


	TCoordinate UnitVector();

	double  dot(TCoordinate op);

	double  cross(TCoordinate op);


	void	AssignXY(double xValue,double yVlaue);

	void	AssignAngle(double Vlaue);

	void	AssignLength(double Vlaue);



	//-----------------------------------------------------------------

	friend TCoordinate  aVector(double xValue , double yValue);

	friend TCoordinate  operator*(TCoordinate op , double scale);

	friend TCoordinate  operator*(double scale , TCoordinate op);

};

double NormalizeAngle(double Angle);
TCoordinate aVector(double xValue , double yValue);
TCoordinate operator*(TCoordinate op , double scale);
TCoordinate operator*(double scale , TCoordinate op);

//---------------------------------------------------------------------------

#endif