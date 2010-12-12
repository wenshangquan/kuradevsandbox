// ����� ���C�� DLL �t�@�C���ł��B

#include "stdafx.h"

#include "ImageConverter.h"

namespace UFOHunt{ namespace Lib {

	// cv::Mat��Drawing::Bitmap�֕ϊ�
	System::Drawing::Bitmap^ ImageConverter::Mat2DotNetBMP(ImageConverterData_cvMat^ mat)
	{
#pragma region �o�b�t�@�Ƀ����������蓖�Ă�
		System::Drawing::Bitmap ^dst = nullptr;
		switch (mat->channels) {
		case 4:
			if (mat->elemSize1 == 1)
				dst = gcnew System::Drawing::Bitmap(
					mat->cols, mat->rows, System::Drawing::Imaging::PixelFormat::Format32bppArgb);
			else if (mat->elemSize1 == 2)
				dst = gcnew System::Drawing::Bitmap(
					mat->cols, mat->rows, System::Drawing::Imaging::PixelFormat::Format64bppArgb);
			break;
		case 3:
			if (mat->elemSize1 == 1)
				dst = gcnew System::Drawing::Bitmap(
					mat->cols, mat->rows, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
			else if (mat->elemSize1 == 2)
				dst = gcnew System::Drawing::Bitmap(
					mat->cols, mat->rows, System::Drawing::Imaging::PixelFormat::Format48bppRgb);
			break;
		case 1:
			if (mat->elemSize1 == 2)
				dst = gcnew System::Drawing::Bitmap(
					mat->cols, mat->rows, System::Drawing::Imaging::PixelFormat::Format16bppGrayScale);
		default:
			dst = gcnew System::Drawing::Bitmap(
				mat->cols, mat->rows, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
		}
#pragma endregion

		// ���ڃA�N�Z�X�J�n
		System::Drawing::Imaging::BitmapData ^data = dst->LockBits(
			*(gcnew System::Drawing::Rectangle(0, 0, dst->Width, dst->Height)), 
			System::Drawing::Imaging::ImageLockMode::ReadWrite, 
			dst->PixelFormat
		);

#pragma region �f�[�^�̃R�s�[����
		// Bitmap�݊��̘A���f�[�^�̏ꍇ�͒P��memcpy���s��
		if ((dst->PixelFormat != System::Drawing::Imaging::PixelFormat::Format24bppRgb
			 || (mat->channels == 3 && mat->elemSize1 == 1 && dst->PixelFormat == System::Drawing::Imaging::PixelFormat::Format24bppRgb))
			 && mat->isContinuous) {
			memcpy(data->Scan0.ToPointer(), mat->data, mat->rows * mat->cols * mat->channels);
		// Bitmap�݊���isContinuous�t���O�������ĂȂ�(�s�A���f�[�^)�ꍇ��1�񂲂ƂɃR�s�[
		} else if (dst->PixelFormat != System::Drawing::Imaging::PixelFormat::Format24bppRgb
			 || (mat->channels == 3 && mat->elemSize1 == 1 && dst->PixelFormat == System::Drawing::Imaging::PixelFormat::Format24bppRgb)) {
			uchar *dp = (uchar *)data->Scan0.ToPointer();
			size_t copystep = mat->elemSize * mat->rows;
			for (int i = 0; i < mat->rows; i++)
				memcpy(dp + copystep * i, mat->data + mat->step * i, copystep);
		// memcpy�ł��Ȃ��ꍇ�͉�f���ɃR�s�[�������s��
		} else {
			if (mat->channels == 1) { // �P�F�摜(�O���[�X�P�[��)�̏ꍇ
				if (mat->elemSize1 == 1) { // 8bit���͍������ׂ̈ɉ��Z���������炷
					uchar *p = (uchar *)data->Scan0.ToPointer();
					for (int i = 0; i < mat->rows * mat->cols; i++) {
						*(p + i * 3) = *(p + i * 3 + 1) = *(p + i * 3 + 2) = *(mat->data + i);
					}
				} else {
					uchar *p = (uchar *)data->Scan0.ToPointer();
					for (int i = 0; i < mat->rows * mat->cols; i++) {
						*(p + i * 3) = *(p + i * 3 + 1) = *(p + i * 3 + 2) = *(mat->data + i * mat->elemSize1 + mat->elemSize);
					}
				}
			} else if (mat->channels == 2) { // �p�r�s��������2�v�f��Mat�̏ꍇ
				if (mat->elemSize1 == 1) { // 8bit���̏ꍇ��R��G�ւ��̂܂ܓW�J
					uchar *p = (uchar *)data->Scan0.ToPointer();
					for (int i = 0; i < mat->rows * mat->cols; i++) {
						memcpy(p + i * 3, mat->data + i * 2, 2);
						*(p + i * 3 + 2) = 0;
					}
				} else if (mat->elemSize1 = 2) { // 16bit���̏ꍇ��R��G�֏��8bit�̂݃R�s�[�B1/256���Ă�B
					uchar *p = (uchar *)data->Scan0.ToPointer();
					for (int i = 0; i < mat->rows * mat->cols * 2; i++) {
						*(p + i * 3) = *(mat->data + i * 4 + 1);
						*(p + i * 3 + 1) = *(mat->data + i * 4 + 3);
						*(p + i * 3 + 2) = 0;
					}
				}
			}
		}
#pragma endregion

		// ���ڃA�N�Z�X�I��
		dst->UnlockBits(data);

		return dst;
	}

	// Drawing::Image��cv::Mat�֕ϊ�(Bitmap������ᑬ)
	ImageConverterData_cvMat^ ImageConverter::DotNetIMG2Mat(System::Drawing::Image^ img)
	{
		return DotNetBMP2Mat(gcnew System::Drawing::Bitmap(img));
	}

	// Drawing::Bitmap��cv::Mat�֕ϊ�
	ImageConverterData_cvMat^ ImageConverter::DotNetBMP2Mat(System::Drawing::Bitmap^ bmp)
	{
		cv::Mat dst(bmp->Height, bmp->Width, CV_8UC3);

		// ���ڃA�N�Z�X�J�n
		System::Drawing::Imaging::BitmapData ^data = bmp->LockBits(
			*(gcnew System::Drawing::Rectangle(0, 0, bmp->Width, bmp->Height)), 
			System::Drawing::Imaging::ImageLockMode::ReadOnly, 
			bmp->PixelFormat
		);

		// �f�[�^�̃R�s�[
		if (System::Drawing::Imaging::PixelFormat::Format24bppRgb == bmp->PixelFormat) {
			memcpy(dst.data, data->Scan0.ToPointer(), bmp->Width * bmp->Height * 3);
		} else if (System::Drawing::Imaging::PixelFormat::Format32bppArgb == bmp->PixelFormat) {
			uchar *pm = dst.data;
			uchar *pb = (uchar *)data->Scan0.ToPointer();
			for (int i = 0; i < bmp->Width * bmp->Height; i++) {
				memcpy(pm + i * 3, pb + i * 4, 3);
			}
		} else {
			uchar *pm = dst.data;
			uchar *pb = (uchar *)data->Scan0.ToPointer();
			for (int i = 0; i < bmp->Width * bmp->Height; i++) {
				*(pm + i * 3) = *(pm + i * 3 + 1) = *(pm + i * 3 + 2) = *(pb + i);
			}
		}

		// ���ڃA�N�Z�X�I��
		bmp->UnlockBits(data);

		return ImageConverterData_cvMat::Create(dst.rows, dst.cols, dst.flags, dst.data, dst.refcount, dst.datastart, dst.dataend);
	}
}}