#ifndef BYTE_ARRAY_READ_H
#define BYTE_ARRAY_READ_H

#include <QByteArray>
#include <QString>
#include <QBuffer>
#include <QDataStream>

class Byte_Array_Read
{
private:
	QByteArray	m_Data;
	QBuffer		m_Queue;
	QDataStream	m_IO;

public:
					Byte_Array_Read(void);
					Byte_Array_Read(const QByteArray Data);
					Byte_Array_Read(const Byte_Array_Read& Other);
					Byte_Array_Read operator =(const Byte_Array_Read& RHS);
					~Byte_Array_Read(void);

	QByteArray		toArray(int Len);
	QString			toString(int Len);
	quint8			toByte(void);
	quint16			toUShort(void);
	quint32			toUInt(void);

	QByteArray		Data_Remain(void);
};


#endif // BYTE_ARRAY_READ_H
