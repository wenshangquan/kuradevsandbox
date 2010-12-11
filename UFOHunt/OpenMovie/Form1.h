#pragma once

namespace OpenMovie {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

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
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  �t�@�C��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �J��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �I��ToolStripMenuItem;
	private: System::Windows::Forms::Label^  label3;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::Label^  loadFileName;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  playRealtime;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->�t�@�C��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�J��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�I��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->loadFileName = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->playRealtime = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(8, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(420, 302);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(434, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(22, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"X �F";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(434, 49);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(22, 12);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Y �F";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->�t�@�C��ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(560, 26);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �t�@�C��ToolStripMenuItem
			// 
			this->�t�@�C��ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->�J��ToolStripMenuItem, 
				this->����ToolStripMenuItem, this->�I��ToolStripMenuItem});
			this->�t�@�C��ToolStripMenuItem->Name = L"�t�@�C��ToolStripMenuItem";
			this->�t�@�C��ToolStripMenuItem->Size = System::Drawing::Size(68, 22);
			this->�t�@�C��ToolStripMenuItem->Text = L"�t�@�C��";
			// 
			// �J��ToolStripMenuItem
			// 
			this->�J��ToolStripMenuItem->Name = L"�J��ToolStripMenuItem";
			this->�J��ToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->�J��ToolStripMenuItem->Text = L"�J��";
			this->�J��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�J��ToolStripMenuItem_Click);
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �I��ToolStripMenuItem
			// 
			this->�I��ToolStripMenuItem->Name = L"�I��ToolStripMenuItem";
			this->�I��ToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->�I��ToolStripMenuItem->Text = L"�I��";
			this->�I��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�I��ToolStripMenuItem_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 338);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 12);
			this->label3->TabIndex = 4;
			this->label3->Text = L"�Đ��t�@�C���F";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Form1::backgroundWorker1_RunWorkerCompleted);
			// 
			// loadFileName
			// 
			this->loadFileName->AutoSize = true;
			this->loadFileName->Location = System::Drawing::Point(88, 338);
			this->loadFileName->Name = L"loadFileName";
			this->loadFileName->Size = System::Drawing::Size(0, 12);
			this->loadFileName->TabIndex = 5;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->playRealtime);
			this->groupBox1->Location = System::Drawing::Point(436, 229);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(114, 100);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"�Đ��ݒ�";
			// 
			// playRealtime
			// 
			this->playRealtime->AutoSize = true;
			this->playRealtime->Checked = true;
			this->playRealtime->CheckState = System::Windows::Forms::CheckState::Checked;
			this->playRealtime->Enabled = false;
			this->playRealtime->Location = System::Drawing::Point(6, 18);
			this->playRealtime->Name = L"playRealtime";
			this->playRealtime->Size = System::Drawing::Size(84, 16);
			this->playRealtime->TabIndex = 0;
			this->playRealtime->Text = L"�����ԍĐ�";
			this->playRealtime->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(560, 360);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->loadFileName);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }

	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
			 }

	private: System::Void �J��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 // �t�@�C���I���_�C�A���O
				 OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
				 System::Windows::Forms::DialogResult^ dr = openFileDialog->ShowDialog();
				 if( dr = System::Windows::Forms::DialogResult::OK ){
					 // TODO: �t�@�C���擾���̏���(����ǂݍ��ݓ�)
					 //MessageBox::Show(openFileDialog->FileName, "caption");

					 // �o�b�N�O���E���h�X���b�h�̒�~
					 if (this->backgroundWorker1->IsBusy) {
						 this->backgroundWorker1->CancelAsync();
						 while (this->backgroundWorker1->IsBusy) {
							 Application::DoEvents();
						 }
					 }
					 if (System::IO::File::Exists(openFileDialog->FileName)) {
						 // �o�b�N�O���E���h�X���b�h�ōĐ������J�n
						 this->backgroundWorker1->RunWorkerAsync(openFileDialog->FileName);
						 this->loadFileName->Text = openFileDialog->FileName;
					 }
				 }
			 }

	private: System::Void �I��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 // TODO: �I�����̏���
				 this->Close();
			 }
	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
				 BackgroundWorker^ worker = safe_cast<BackgroundWorker^>(sender);

				 // �t�@�C������ǂݍ���
				 char *path = (char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(safe_cast<String^>(e->Argument)).ToPointer();

				 cv::VideoCapture cap(path);
				 if (!cap.isOpened()) {
					 MessageBox::Show(safe_cast<String^>(e->Argument), "Don't open");
					 return;
				 }
				 // �t���[���擾�p�ϐ�
				 cv::Mat frame;
				 // �Đ����ԊǗ�
				 DateTime start = DateTime::Now;
				 while (1) {
					 if (worker->CancellationPending)
						 break;

					 // �����ԍĐ����Đ��^�C�~���O����(���s�R�[�h)
					 /*
					 if (this->playRealtime->Checked) {
						 TimeSpan ts = DateTime::Now - start;
						 cap.set(CV_CAP_PROP_POS_MSEC, ts.TotalMilliseconds);
					 }
					 */

					 // �t���[���擾
					 cap >> frame;
					 if (frame.empty())
						 break;

					 // ���T�C�Y
					 cv::Mat resized(this->pictureBox1->Width * frame.rows / frame.cols, this->pictureBox1->Width, frame.type());
					 cv::resize(frame, resized, resized.size());

					 // ��ʂɕ\��
					 this->pictureBox1->Image = UFOHunt::Lib::ImageConverter::Mat2DotNetBMP(
							UFOHunt::Lib::ImageConverterData_cvMat::Create(resized.rows, resized.cols, resized.flags, resized.data));
				 }
				 
				 // �q�[�v�Ɋm�ۂ��ꂽ�t�@�C���p�X�����
				 System::Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr(path));
			 }
private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			 this->loadFileName->Text = "";
			 this->pictureBox1->Image = nullptr;
		 }
};
}

