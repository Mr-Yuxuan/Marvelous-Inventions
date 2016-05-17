#include"BigData.h"
BigData::BigData(const long long value)
         :_value(value),
		  _isvalueov(true)
{
	_sdata.resize(Disgit(value));
	Itoa(value);
	if (value<0)
	{
		_sdata.insert(0, 1, '-');
	}
	else
	{
		_sdata.insert(0, 1, '+');
	}

}
BigData::BigData(const char* data)
           :_sdata(data),
            _isvalueov(true)
{
	if (*data <= '9'&&*data >= '0')
	{
		_sdata.insert(0, 1, '+');
	}
	_value = 0;
	int state = 1;
	_value = Aoti(data, state);
	if (state == -1)
	{
		cout << "构造参数有误,请给纯数字参数" << endl;
		system("pause");
		exit(0);
	}
	
}
//判断数值是否溢出
long long BigData::Aoti(const char* data,int& state)
{
	int flag = 1;
	while (*data)
	{
		if (*data == '-')
		{
			flag = -1;
			data++;
			continue;
		}
		if (*data == '+')
		{
			data++;
			continue;
		}
		if (*data <= '9'&&*data >= '0')
		{
			if (_value < MAXINT64/10)
			{
				_value = _value * 10 + (*data - '0');
			}
			else
			{
				if ((_value < MAXINT64 / 10)&&(Disgit(_value)<Disgit(MAXINT64)) && ((*data - '0' <= 7) || (flag == -1 && *data - '0' <= 7)))
				{
					_value = _value * 10 + *data - '0';
				}
				else
				{
					_isvalueov = false;
					
				}
			}
			data++;
		}
		else
		{
			state = -1;
			break;
		}

	}
	return flag*_value;
}
size_t BigData::Disgit(long long value)
{
	size_t count = 0;
	while (value)
	{
		value = value /10;
		count++;
	}
	return count;
}
ostream& operator<<(ostream& os, const BigData d)
{
	if (d._sdata[0] == '-')
	{
		os << '-';
	}
	size_t i = 1;
	while (1)
	{
		if (d._sdata[i] == '0')
		{
			++i;
		}
		else
			break;
	}
	for (; i < d._sdata.size(); ++i)
	{

		os << d._sdata[i];
	}
	
	//if (d._isvalueov == true)
	//{
	//	os << d._value;
	//}
	return os;
}
//判断同号两数相加结果是否溢出
bool BigData::IsOvOfSum(long long Lvalue, long long Rvalue)
{
	if (Lvalue < 0)
	{
		if (MININT64 - Lvalue <= Rvalue)
			return true;
		else
			return false;
	}
	else
	{
		if (MAXINT64 - Lvalue >= Rvalue)
			return true;
		else
			return false;
	}

}
//判断同号两数相乘结果是否溢出
bool BigData::IsOvOfMul(long long Lvalue, long long Rvalue)
{
	if (Lvalue < 0&&Rvalue>0)
	{
		if (MININT64 / Lvalue >= Rvalue)
			return true;
		else
			return false;
	}
	if (Lvalue > 0 && Rvalue<0)
	{
		if (MININT64 / Lvalue <= Rvalue)
			return true;
		else
			return false;
	}
	if (Lvalue > 0 && Rvalue>0)
	{
		if (MAXINT64 / Lvalue >= Rvalue)
			return true;
		else
			return false;
	}
	if (Lvalue < 0 && Rvalue<0)
	{
		if (MAXINT64 / Lvalue <= Rvalue)
			return true;
		else
			return false;
	}

}
BigData BigData::operator+( BigData b)
{
	string s;
	if (_isvalueov&&b._isvalueov)
	{
		if (_sdata[0] != b._sdata[0])
			return _value + b._value;
		else
		{
			if (IsOvOfSum(_value, b._value))
				return _value + b._value;
			else
				return _Add(_sdata, b._sdata,s);
		}
	}
	else
	{
		if (_sdata[0] != b._sdata[0])
		    return _Sub(_sdata, b._sdata,s);
		else
		    return _Add(_sdata, b._sdata,s);
	}
}
char* BigData::_Add(string& left, string& right,string& s)
{
	size_t Lsize = left.size();
	size_t Rsize = right.size();
	if (Lsize < Rsize)
	{
		swap(left, right);
		swap(Lsize, Rsize);
	}
	size_t carry = 0;
	s.resize(Lsize+1,'0');
	s[0] = left[0];
	for (size_t i = 1; i < Lsize+1; ++i)
	{
		
		size_t val = 0;
		if (i < Rsize)
		{
			val = (left[Lsize - i] - '0') + (right[Rsize - i] - '0') + carry;
			
		}
		else if (i<Lsize)
		{
			val = left[Lsize - i] - '0' + carry;
		}
		else
		{
			val += carry;
		}
		carry = 0;
		if (val >= 10)
		{
			carry = val / 10;
			val %= 10;
		}
		s[Lsize+1 - i] = val + '0';
	}
	
	return (char*)s.c_str();
	
}
void BigData::Itoa(long long value)
{
	size_t sz = _sdata.size()-1;
	if (value < 0)
	{
		value = -value;
	}
	while (value)
	{
		_sdata[sz--] = value % 10+'0';
		value /= 10;
	}
	return;
}
BigData BigData::operator-( BigData b)
{
	string s;
	if (_isvalueov&&b._isvalueov)
	{
		if (_sdata[0] == b._sdata[0])
			return _value - b._value;
		else
		{
			if (IsOvOfSum(_value, -b._value))
				return _value - b._value;
			else
			    return _Add(_sdata, b._sdata,s);
			
		}
	}
	else
	{
		if (_sdata[0] == b._sdata[0])
			return _Sub(_sdata, b._sdata,s);
		else
		    return _Add(_sdata, b._sdata,s);
		
	}
}
char* BigData::_Sub(string& left, string& right, string& s)
{
	size_t Lsize = left.size();
	size_t Rsize = right.size();
	if (left[0]=='+'&&(Lsize < Rsize || ((Lsize == Rsize)&&(left.compare(right) < 0))))
	{
		swap(left, right);
		swap(Lsize, Rsize);
		left[0] = '-';
	}
	if (left[0] == '-' && (Lsize < Rsize || ((Lsize == Rsize) && (left.compare(right) < 0))))
	{
		swap(left, right);
		swap(Lsize, Rsize);
		left[0] = '+';
	}
	s.resize(Lsize,'0');
	s[0] = left[0];
	for (size_t i = 1; i < Lsize; ++i)
	{
		int val = 0;
		if (i < Rsize)
		{
			val = (left[Lsize - i] - '0') - (right[Rsize - i] - '0');
		}
		else
		{
			val = left[Lsize - i]-'0';
		}
		if (val < 0)
		{
			left[Lsize - i - 1] -= 1;
			val += 10;
		}
		s[Lsize - i] = val + '0';
	}
	return (char*)s.c_str();
}
BigData BigData::operator*(BigData b)
{
	string s;
	if (_isvalueov&&b._isvalueov)
	{
		if (IsOvOfMul(_value, b._value))
			return _value*b._value;
		else
		{
			if (_value == 0 || b._value == 0)
			{
				return (long long)(0);
			}
			return _Mul(_sdata, b._sdata, s);
		}
	}
	else
	{
		return _Mul(_sdata, b._sdata, s);
	}
}
char* BigData::_Mul(string& left, string& right, string& s)
{
	size_t Lsize = left.size();
	size_t Rsize = right.size();
	
	if (Lsize > Rsize)
	{
		swap(Lsize, Rsize);
		swap(left, right);
	}
	s.resize(Lsize + Rsize - 1,'0');
	if (left[0] != right[0])
	{
		s[0] = '-';
	}
	else
		s[0] = '+';
	size_t carry1 = 0;
	size_t carry2 = 0;
	size_t offset = 0;
	for (size_t i = 1; i < Lsize; ++i)
	{
		if (left[i] != '0')
		{
            for (size_t j = 1; j < Rsize; ++j)
			{
				size_t val = (left[i] - '0') * (right[j] - '0') + carry1;
				carry1 = 0;
				if (val>=10)
				{
					carry1 = val / 10;
					val %= 10;
				}
				size_t tmp = s[Lsize + Rsize - 1 - j - offset] - '0' + val+carry2;
				carry2 = 0;
				if (tmp>=10)
				{
					carry2 = tmp / 10;
					tmp %= 10;
				}
				s[Lsize + Rsize - 1 - j - offset] = tmp + '0';
			}
			if (carry1 != 0||carry2!=0)
			{
				s[Lsize -1- offset] += carry1+carry2;
				carry1 = 0;
				carry2 = 0;
			}
		}
		offset++;
	}
	
	return (char*)s.c_str();
}
BigData BigData::operator/(BigData b)
{
	string s;
	if (b._value == 0)
	{
		assert(false);
	}
	if (b._value == 1)
	{
		return *this;
	}
	if (b._value == -1)
	{
		if (_sdata[0] == '+')
		{
			_sdata[0] = '-';
		}
		else
			_sdata[0] = '+';
		return *this;
	}
	if (_sdata.size()<b._sdata.size() || ((_sdata.size()==b._sdata.size())&&(strcmp((char*)_sdata.c_str() + 1, (char*)b._sdata.c_str() + 1) < 0)))
	{
		return (long long)(0);
	}
	if (_isvalueov&&b._isvalueov)
	{

		return _value / b._value;
	}
	else
	{
		return _Div(_sdata, b._sdata, s);
	}
}
char* BigData::_Div(string& left, string& right, string& s)
{
	if (left[0] == right[0])
	{
		s.append(1, '+');
	}
	else
	{
		s.append(1, '-');
	}
	size_t Lsize = left.size();
	size_t Rsize = right.size();
	size_t idex = 0;
	size_t len = 1;
	char* pleft = (char*)left.c_str() + 1;
	char* pright = (char*)right.c_str() + 1;
	while ((*pleft != '\0')&&(*(pleft + len-1) != '\0'))
	{
		if (*pleft == '0')
		{
			s.append(1, '0');
			pleft++;
			continue;
		}
		if (!LeftBig(pleft, len, pright, Rsize - 1))
		{
			s.append(1, '0');
			len++;
			continue;
		}
		char ret = SubLoop(pleft, len, pright, Rsize - 1)+'0';
		s.append(1, ret);
		len++;
	}
	return (char*)s.c_str();
}
size_t BigData::SubLoop(char* &pleft,size_t& plsize,char* pright,size_t prsize)
{
	size_t count = 0;
	
	int val = 0;
	while (1)
	{
		size_t lsize = plsize - 1;
		size_t rsize = prsize - 1;
		if (!LeftBig(pleft,plsize,pright,prsize))
		{
			break;
		}
		for (size_t i = 0; i <= lsize; ++i)
		{
			if (i <= rsize)
			{
				val = (pleft[lsize - i] - '0') - (pright[rsize - i] - '0');
			}
			else
			{
				val = pleft[lsize - i] - '0';
			}
			if (val < 0)
			{
				pleft[lsize - i-1] -= 1;
				val += 10;
			}
			pleft[lsize - i] = val + '0';
		}
		while (*pleft == '0'&&plsize>0)
		{
			pleft++;
			plsize--;
		}
		count++;
		
	}
	return count;
}
bool BigData::LeftBig(char *pleft, size_t plsize, char* pright, size_t prsize)
{
	if (plsize < prsize || (plsize == prsize&&strncmp(pleft, pright, plsize)<0))
	{
		return false;
	}
	return true;
}