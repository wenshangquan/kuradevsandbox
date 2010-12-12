#pragma once

namespace OpenCVTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 �̊T�v
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button2;


	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"���C���I", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(640, 479);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(640, 480);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"�W��", L"�O���[�X�P�[��"});
			this->comboBox1->Location = System::Drawing::Point(12, 497);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 20);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->Text = L"�W��";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(577, 495);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Save";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(664, 529);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->Text = L"CapTest";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private:
	// CmboBox�̃C���f�b�N�X�l(�A�N�Z�X�������p)
	int cboxIndex;

	// �C���[�W��PictureBox�֕\��������
	System::Void Image(cv::Mat *img)
	{
		this->pictureBox1->Image = UFOHunt::Lib::ImageConverter::Mat2DotNetBMP(
			UFOHunt::Lib::ImageConverterData_cvMat::Create(img->rows, img->cols, img->flags, img->data));
	}

private: 
	// .NET�̃X���b�h�N���X
	System::Threading::Thread^ th;
	// �X���b�h�N���X����Ă΂��R�[���o�b�N�֐�
	static void th_callback(System::Object^ obj) 
	{
		// �X���b�h�̃I�[�i�[�C���X�^���X���擾
		Form1^ owner = dynamic_cast<Form1^>(obj);

		// �L���v�`���f�o�C�X�̏���
		cv::VideoCapture cap(0);
		if (!cap.isOpened())
			MessageBox::Show("Cam Open Error");
		
		// �J�����ݒ�
		cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
		//cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480); // �����̂��ȗ��\�B�ڍׂ�cvcap_dshow.cpp��156�s������(Ver2.1.0��)�Q��

		// �L���v�`������
		try {
			while (1) { 
				cv::Mat frame;
				cap >> frame;
				cv::Mat filterd;
				// �t�B���^����
				switch (owner->cboxIndex) {
					case 0:  // �W��
					default: // �W���Ɠ���
						break;
					case 1: // �O���[�X�P�[��
						cvtColor(frame, filterd, CV_RGB2GRAY);
						break;
				}
				if (filterd.empty())
					owner->Image(&frame);
				else
					owner->Image(&filterd);
			}
		} catch (System::Threading::ThreadAbortException^ e) {
			System::Diagnostics::Trace::WriteLine("�f���X���b�h�I���Ȃ��B\n" + e->ToString());
		}
	}

	// Start�{�^���N���b�N�C�x���g
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		// �ז��ȃ{�^�����\���ɂ���
		this->button1->Visible = false;

		// �X���b�h�쐬���ċN��
		th = gcnew System::Threading::Thread(gcnew System::Threading::ParameterizedThreadStart(&Form1::th_callback));
		th->Start(this);
	}

	// �t�H�[������钼�O�ɌĂ΂��C�x���g
	private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		if (nullptr != th) {
			th->Abort();
			th->Join();
		}
	}
	// �X���b�h�ԃA�N�Z�X������������邽�߂̑������
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		cboxIndex = comboBox1->SelectedIndex;
	}
	// �ۑ��{�^������(���܂�)
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		// �r�f�I�Đ��O�͎��s���Ȃ�
		if (button1->Visible == true) return;

		// �o�̓f�B���N�g���p�X
		String^ saveDir = ".\\Save\\";
		// �o�̓t�@�C���ԍ�
		int saveNo = 0;

		ArrayList^ files = gcnew ArrayList();

		// �o�̓f�B���N�g���̑��݃`�F�b�N
		if (IO::Directory::Exists(saveDir)) {
			// �o�̓f�B���N�g�����̃t�@�C�����X�g�擾
			files->AddRange(IO::Directory::GetFiles(saveDir, "Save????.jpg"));
			// �o�̓t�@�C���ԍ��̍ő�l���擾
			if (files->Count > 0) {
			files->Sort();
			saveNo = Int32::Parse(dynamic_cast<String^>(files[files->Count - 1])->Substring(saveDir->Length + 4, 4)) + 1;
			}
		} else {
			IO::Directory::CreateDirectory(saveDir);
		}
		// jpg�Ńt�@�C����ۑ�
		System::Diagnostics::Trace::WriteLine("SaveName => " + String::Format(saveDir + "Save{0:D4}.jpg", saveNo));
		pictureBox1->Image->Save(String::Format(saveDir + "Save{0:D4}.jpg", saveNo), System::Drawing::Imaging::ImageFormat::Jpeg);
	}
};

	
}

