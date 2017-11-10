#include <QDebug>
#include <QtEndian>

#include "Byte_Array_Read.h"

// ===================================================================================
// Constructor
Byte_Array_Read::Byte_Array_Read(void)
{
	this->m_Data = QByteArray();
	this->m_Queue.setBuffer(&this->m_Data);
	this->m_Queue.open(QIODevice::ReadOnly);
	this->m_IO.setDevice(&this->m_Queue);
	this->m_IO.setByteOrder(QDataStream::LittleEndian);
}
Byte_Array_Read::Byte_Array_Read(const QByteArray Data)
{
	this->m_Data = Data;
	this->m_Queue.setBuffer(&this->m_Data);
	this->m_Queue.open(QIODevice::ReadOnly);
	this->m_IO.setDevice(&this->m_Queue);
	this->m_IO.setByteOrder(QDataStream::LittleEndian);
}
Byte_Array_Read::Byte_Array_Read(const Byte_Array_Read& Other)
{
	this->m_Data = Other.m_Data;
	this->m_Queue.setBuffer(&this->m_Data);
	this->m_Queue.open(QIODevice::ReadOnly);
	this->m_Queue.seek(Other.m_Queue.pos());
	this->m_IO.setDevice(&this->m_Queue);
	this->m_IO.setByteOrder(QDataStream::LittleEndian);
}
Byte_Array_Read Byte_Array_Read::operator =(const Byte_Array_Read& RHS)
{
	this->m_Data = RHS.m_Data;
	this->m_Queue.setBuffer(&this->m_Data);
	this->m_Queue.open(QIODevice::ReadOnly);
	this->m_Queue.seek(RHS.m_Queue.pos());
	this->m_IO.setDevice(&this->m_Queue);
	this->m_IO.setByteOrder(QDataStream::LittleEndian);

	return *this;
}

Byte_Array_Read::~Byte_Array_Read()
{
	this->m_Queue.close();
}

// ===================================================================================
// Methods
QByteArray Byte_Array_Read::toArray(int Len)
{
	QByteArray Retreived;
	Retreived.resize(Len);

	if(this->m_IO.readRawData(Retreived.data(), Len)!=Len)
	{
		QString Error_Message = QString("Out of data when retrived %1 bytes").arg(Len);
		qWarning() << Error_Message;
		throw Error_Message;
	}

	return Retreived;
}
QString Byte_Array_Read::toString(int Len)
{
	QByteArray Data = this->toArray(Len);

	return QString(Data);
}
quint8 Byte_Array_Read::toByte(void)
{
	quint8	Retrived;

	this->m_IO >> Retrived;
	if(this->m_IO.status()!=QDataStream::Ok)
	{
		QString Error_Message = QString("Out of data when retrived 'quint8'");
		qWarning() << Error_Message;
		throw Error_Message;
	}

	return Retrived;
}
quint16 Byte_Array_Read::toUShort(void)
{
	quint16	Retrived;

	this->m_IO >> Retrived;
	if(this->m_IO.status()!=QDataStream::Ok)
	{
		QString Error_Message = QString("Out of data when retrived 'quint16'");
		qWarning() << Error_Message;
		throw Error_Message;
	}

	return Retrived;
}
quint32 Byte_Array_Read::toUInt(void)
{
	quint32	Retrived;

	this->m_IO >> Retrived;
	if(this->m_IO.status()!=QDataStream::Ok)
	{
		QString Error_Message = QString("Out of data when retrived 'quint32'");
		qWarning() << Error_Message;
		throw Error_Message;
	}

	return Retrived;
}

// ===================================================================================
// Properties
QByteArray Byte_Array_Read::Data_Remain(void)
{
	return this->m_Queue.readAll();
}
