/*************************************************************************
Copyright (c) 2012-2014 Miroslav Andel
All rights reserved.

For conditions of distribution and use, see copyright notice in sgct.h 
*************************************************************************/

#include "../include/sgct/SharedDataTypes.h"
#include "../include/sgct/SGCTMutexManager.h"

sgct::SharedFloat::SharedFloat()
{
	mVal = 0.0f;
}

sgct::SharedFloat::SharedFloat(float val)
{
	mVal = val;
}

sgct::SharedFloat::SharedFloat(const SharedFloat & sf)
{
	mVal = sf.mVal;
}

float sgct::SharedFloat::getVal()
{
	float tmpVal;

	SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	tmpVal = mVal;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );

	return tmpVal;
}

void sgct::SharedFloat::setVal(float val)
{
	SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	mVal = val;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
}

void sgct::SharedFloat::operator=(const SharedFloat & sf)
{
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	mVal = sf.mVal;
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
}

void sgct::SharedFloat::operator=(const float & val)
{
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	mVal = val;
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
}

void sgct::SharedFloat::operator+=(const float & val)
{
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	mVal += val;
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
}

void sgct::SharedFloat::operator-=(const float & val)
{
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	mVal -= val;
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
}

void sgct::SharedFloat::operator*=(const float & val)
{
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	mVal *= val;
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
}

void sgct::SharedFloat::operator/=(const float & val)
{
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	mVal /= val;
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
}

void sgct::SharedFloat::operator++()
{
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	mVal += 1.0f;
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
}

void sgct::SharedFloat::operator--()
{
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	mVal -= 1.0f;
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
}

bool sgct::SharedFloat::operator<(const float & val)
{
	bool tmpB;
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	tmpB = (mVal < val);
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
	return tmpB;
}

bool sgct::SharedFloat::operator<=(const float & val)
{
	bool tmpB;
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	tmpB = (mVal <= val);
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
	return tmpB;
}

bool sgct::SharedFloat::operator>(const float & val)
{
	bool tmpB;
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	tmpB = (mVal > val);
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
	return tmpB;
}

bool sgct::SharedFloat::operator>=(const float & val)
{
	bool tmpB;
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	tmpB = (mVal >= val);
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
	return tmpB;
}

bool sgct::SharedFloat::operator==(const float & val)
{
	bool tmpB;
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	tmpB = (mVal == val);
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
	return tmpB;
}

bool sgct::SharedFloat::operator!=(const float & val)
{
	bool tmpB;
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	tmpB = (mVal != val);
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
	return tmpB;
}

float sgct::SharedFloat::operator+(const float & val)
{
	float tmpF;
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	tmpF = (mVal + val);
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
	return tmpF;
}

float sgct::SharedFloat::operator-(const float & val)
{
	float tmpF;
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	tmpF = (mVal - val);
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
	return tmpF;
}

float sgct::SharedFloat::operator*(const float & val)
{
	float tmpF;
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	tmpF = (mVal * val);
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
	return tmpF;
}

float sgct::SharedFloat::operator/(const float & val)
{
	float tmpF;
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	tmpF = (mVal / val);
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
	return tmpF;
}

sgct::SharedDouble::SharedDouble()
{
	mVal = 0.0;
}

sgct::SharedDouble::SharedDouble(double val)
{
	mVal = val;
}

sgct::SharedDouble::SharedDouble( const SharedDouble & sd )
{
	mVal = sd.mVal;
}

double sgct::SharedDouble::getVal()
{
	double tmpVal;

	SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	tmpVal = mVal;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );

	return tmpVal;
}

void sgct::SharedDouble::setVal(double val)
{
	SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	mVal = val;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
}

void sgct::SharedDouble::operator=(const SharedDouble & sd)
{
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	mVal = sd.mVal;
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
}

void sgct::SharedDouble::operator=( const double & val )
{
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	mVal = val;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
}

void sgct::SharedDouble::operator+=( const double & val )
{
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	mVal += val;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
}

void sgct::SharedDouble::operator-=( const double & val )
{
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	mVal -= val;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
}

void sgct::SharedDouble::operator*=( const double & val )
{
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	mVal *= val;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
}

void sgct::SharedDouble::operator/=( const double & val )
{
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	mVal /= val;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
}

void sgct::SharedDouble::operator++()
{
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	mVal += 1.0;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
}

void sgct::SharedDouble::operator--()
{
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	mVal -= 1.0;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
}

bool sgct::SharedDouble::operator<( const double & val )
{
    bool tmpB;
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
    tmpB = (mVal < val);
    SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
    return tmpB;
}

bool sgct::SharedDouble::operator<=( const double & val )
{
    bool tmpB;
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
    tmpB = (mVal <= val);
    SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
    return tmpB;
}

bool sgct::SharedDouble::operator>( const double & val )
{
    bool tmpB;
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
    tmpB = (mVal > val);
    SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
    return tmpB;
}

bool sgct::SharedDouble::operator>=( const double & val )
{
    bool tmpB;
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
    tmpB = (mVal >= val);
    SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
    return tmpB;
}

bool sgct::SharedDouble::operator==( const double & val )
{
    bool tmpB;
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
    tmpB = (mVal == val);
    SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
    return tmpB;
}

bool sgct::SharedDouble::operator!=( const double & val )
{
    bool tmpB;
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
    tmpB = (mVal != val);
    SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
    return tmpB;
}

double sgct::SharedDouble::operator+( const double & val )
{
    double tmpD;
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
    tmpD = (mVal + val);
    SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
    return tmpD;
}

double sgct::SharedDouble::operator-( const double & val )
{
    double tmpD;
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
    tmpD = (mVal - val);
    SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
    return tmpD;
}

double sgct::SharedDouble::operator*( const double & val )
{
    double tmpD;
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
    tmpD = (mVal * val);
    SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
    return tmpD;
}

double sgct::SharedDouble::operator/( const double & val )
{
    double tmpD;
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
    tmpD = (mVal / val);
    SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
    return tmpD;
}


sgct::SharedInt::SharedInt()
{
	mVal = 0;
}

sgct::SharedInt::SharedInt(int val)
{
	mVal = val;
}

int sgct::SharedInt::getVal()
{
	int tmpVal;

	SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	tmpVal = mVal;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );

	return tmpVal;
}

void sgct::SharedInt::setVal(int val)
{
	SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	mVal = val;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
}

sgct::SharedUChar::SharedUChar()
{
	mVal = 0;
}

sgct::SharedUChar::SharedUChar(unsigned char val)
{
	mVal = val;
}

unsigned char sgct::SharedUChar::getVal()
{
	unsigned char tmpVal;

	SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	tmpVal = mVal;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );

	return tmpVal;
}

void sgct::SharedUChar::setVal(unsigned char val)
{
	SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	mVal = val;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
}

sgct::SharedBool::SharedBool()
{
	mVal = false;
}

sgct::SharedBool::SharedBool(bool val)
{
	mVal = val;
}

sgct::SharedBool::SharedBool( const SharedBool & sd )
{
    mVal = sd.mVal;
}

bool sgct::SharedBool::getVal()
{
	bool tmpVal;

	SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	tmpVal = mVal;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );

	return tmpVal;
}

void sgct::SharedBool::setVal(bool val)
{
	SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	mVal = val;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
}

void sgct::SharedBool::toggle()
{
	SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	mVal = !mVal;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
}

void sgct::SharedBool::operator=( const bool & val )
{
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	mVal = val;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
}

void sgct::SharedBool::operator=(const SharedBool & sb)
{
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	mVal = sb.mVal;
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
}

bool sgct::SharedBool::operator==( const bool & val )
{
    bool tmpB;
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
    tmpB = (mVal == val);
    SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
    return tmpB;
}

bool sgct::SharedBool::operator!=( const bool & val )
{
    bool tmpB;
    SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
    tmpB = (mVal != val);
    SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
    return tmpB;
}

sgct::SharedShort::SharedShort()
{
	mVal = 0;
}

sgct::SharedShort::SharedShort(short val)
{
	mVal = val;
}

short sgct::SharedShort::getVal()
{
	short tmpVal;

	SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	tmpVal = mVal;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );

	return tmpVal;
}

void sgct::SharedShort::setVal(short val)
{
	SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	mVal = val;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
}

sgct::SharedString::SharedString()
{
	;
}

sgct::SharedString::SharedString(const std::string & str)
{
	mStr.assign(str);
}

sgct::SharedString::SharedString(const SharedString & ss)
{
	mStr = ss.mStr;
}

std::string sgct::SharedString::getVal()
{
	std::string tmpStr;

	SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	tmpStr.assign( mStr );
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );

	return tmpStr;
}

void sgct::SharedString::setVal(const std::string & str)
{
	SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	mStr.assign(str);
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
}

void sgct::SharedString::clear()
{
	SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	mStr.clear();
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
}

void sgct::SharedString::operator=(const std::string & str)
{
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	mStr = str;
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
}

void sgct::SharedString::operator=(const SharedString & ss)
{
	SGCTMutexManager::instance()->lockMutex(SGCTMutexManager::SharedVariableMutex);
	mStr = ss.mStr;
	SGCTMutexManager::instance()->unlockMutex(SGCTMutexManager::SharedVariableMutex);
}

/*
template <class T>
sgct::SharedObject<T>::SharedObject()
{
	;
}

template <class T>
sgct::SharedObject<T>::SharedObject(T val)
{
	mVal = val;
}

template <class T>
T sgct::SharedObject<T>::getVal()
{
	T tmpT;
	SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	tmpT = mVal;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
	return tmpT;
}

template <class T>
void sgct::SharedObject<T>::setVal(T val)
{
	SGCTMutexManager::instance()->lockMutex( SGCTMutexManager::SharedVariableMutex );
	mVal = val;
	SGCTMutexManager::instance()->unlockMutex( SGCTMutexManager::SharedVariableMutex );
}
*/
