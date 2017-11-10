#include <QDebug>

#include "Byte_Array_Write.h"

// ===================================================================================
// Constructor
Byte_Array_Write::Byte_Array_Write(void)
{
	this->m_Queue.setBuffer(&this->m_Data);
	this->m_Queue.open(QIODevice::WriteOnly);
	this->m_IO.setDevice(&this->m_Queue);
	this->m_IO.setByteOrder(QDataStream::LittleEndian);
}
Byte_Array_Write::Byte_Array_Write(const QByteArray Data)
{
	this->m_Data = Data;
	this->m_Queue.setBuffer(&this->m_Data);
	this->m_Queue.open(QIODevice::WriteOnly);
	this->m_IO.setDevice(&this->m_Queue);
	this->m_IO.setByteOrder(QDataStream::LittleEndian);
}
Byte_Array_Write::Byte_Array_Write(const Byte_Array_Write& Other)
{
	this->m_Data = Other.m_Data;
	this->m_Queue.setBuffer(&this->m_Data);
	this->m_Queue.open(QIODevice::WriteOnly);
	this->m_Queue.seek(Other.m_Queue.pos());
	this->m_IO.setDevice(&this->m_Queue);
	this->m_IO.setByteOrder(QDataStream::LittleEndian);
}
Byte_Array_Write Byte_Array_Write::operator =(const Byte_Array_Write& RHS)
{
	this->m_Data = RHS.m_Data;
	this->m_Queue.setBuffer(&this->m_Data);
	this->m_Queue.open(QIODevice::WriteOnly);
	this->m_Queue.seek(RHS.m_Queue.pos());
	this->m_IO.setDevice(&this->m_Queue);
	this->m_IO.setByteOrder(QDataStream::LittleEndian);

	return *this;
}

Byte_Array_Write::~Byte_Array_Write()
{
	this->m_Queue.close();
}

// ===================================================================================
// Methods
void Byte_Array_Write::Append(const quint8 Data)
{
	this->m_IO << Data;
	if(this->m_IO.status()!=QDataStream::Ok)
	{
		QString Error_Message = QString("Out of data when retrived 'quint8'");
		qWarning() << Error_Message;
		throw Error_Message;
	}
}
void Byte_Array_Write::Append(const quint16 Data)
{
	this->m_IO << Data;
	if(this->m_IO.status()!=QDataStream::Ok)
	{
		QString Error_Message = QString("Out of data when retrived 'quint8'");
		qWarning() << Error_Message;
		throw Error_Message;
	}
}
void Byte_Array_Write::Append(const quint32 Data)
{
	this->m_IO << Data;
	if(this->m_IO.status()!=QDataStream::Ok)
	{
		QString Error_Message = QString("Out of data when retrived 'quint8'");
		qWarning() << Error_Message;
		throw Error_Message;
	}

//	quint32 Value = qFromBigEndian(Data);
//	this->m_Data.append((char)((Value & 0xFF000000) >> 24));
//	this->m_Data.append((char)((Value & 0x00FF0000) >> 16));
//	this->m_Data.append((char)((Value & 0x0000FF00) >> 8));
	//	this->m_Data.append((char)((Value & 0x000000FF) >> 0));
}

void Byte_Array_Write::Append(const QByteArray Data,const int Len)
{
	QByteArray	Append_Data = Data.left(Len);
	int			Count = Len - Append_Data.size();

	while(Count)
	{
		Append_Data.append((char)0);
		Count--;
	}

	if(this->m_IO.writeRawData(Append_Data.data(), Len)!=Len)
	{
		QString Error_Message = QString("Out of data when writing %1 bytes'").arg(Len);
		qWarning() << Error_Message;
		throw Error_Message;
	}
}
void Byte_Array_Write::Append(const QString Data,const int Len)
{
	this->Append(Data.toUtf8(), Len);
}

//bool Byte_Array_Write::Resize(const quint32 NewSize)
//{
//	if(NewSize > (quint32)this->m_Data.size())	return false;

//	this->m_Data = this->m_Data.left(NewSize);
//	return true;
//}

// ===================================================================================
// Properties
QByteArray Byte_Array_Write::Data_Output()
{
	return this->m_Data;
}

