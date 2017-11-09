#ifndef BYTE_ARRAY_WRITE_H
#define BYTE_ARRAY_WRITE_H

#include <QByteArray>
#include <QBuffer>
#include <QDataStream>
#include <QString>

class Byte_Array_Write
{
private:
	QByteArray	m_Data;
	QBuffer		m_Queue;
	QDataStream	m_IO;

public:
	                    Byte_Array_Write(void);
						Byte_Array_Write(const QByteArray Data);
						Byte_Array_Write(const Byte_Array_Write& Other);
						Byte_Array_Write operator =(const Byte_Array_Write& RHS);
						~Byte_Array_Write(void);

	void				Append(const quint8 Data);
	void				Append(const quint16 Data);
	void				Append(const quint32 Data);
	void				Append(const QByteArray Data, int Len = 0);
	void				Append(const QString Data, int Len = 0);

//	bool				Resize(quint32 NewSize);
//	Byte_Array_Write	Data_Output(void);

	QByteArray			Data_Output(void);

};


#endif // BYTE_ARRAY_WRITE_H
