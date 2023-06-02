#pragma once
#include "game_lib.h"
#include "data_format.h"
#include "pch.h"
#include<math.h>

int system_counter = 0;
float X = 0;
float Y = 0;
float Theta = 1.57;
float V = 0;
float W = 0;
float dt = 0.1;


namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		System::Drawing::Point panel2StartPos;

		Form1(void)
		{
			InitializeComponent();

			panel2StartPos = panel2->Location;
			
			// 導入背景圖像
			Image^ background = Image::FromFile("C:/Users/USER/OneDrive/桌面/程式語言與應用/Final_5_25-master/resource/back.ico");
			
			// 設置窗口背面圖像
			this->BackgroundImage = background;
			this->BackgroundImageLayout = ImageLayout::Stretch;

			
			// 導入方向鍵圖像
			Image^ image_up = Image::FromFile("C:/Users/USER/OneDrive/桌面/程式語言與應用/Final_5_25-master/resource/up.png");
			Image^ image_left = Image::FromFile("C:/Users/USER/OneDrive/桌面/程式語言與應用/Final_5_25-master/resource/left.png");
			Image^ image_right = Image::FromFile("C:/Users/USER/OneDrive/桌面/程式語言與應用/Final_5_25-master/resource/right.png");
			Image^ image_down = Image::FromFile("C:/Users/USER/OneDrive/桌面/程式語言與應用/Final_5_25-master/resource/down.png");
			Image^ image_stop = Image::FromFile("C:/Users/USER/OneDrive/桌面/程式語言與應用/Final_5_25-master/resource/stop.png");

			// 設置按鈕的背景圖像
			button1->BackgroundImage = image_up;
			button2->BackgroundImage = image_left;
			button3->BackgroundImage = image_right;
			button4->BackgroundImage = image_down;
			button5->BackgroundImage = image_stop;

			

		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ProgressBar^ progressBar3;
	private: System::Windows::Forms::ProgressBar^ progressBar2;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button5;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->progressBar3 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->Location = System::Drawing::Point(1214, 523);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 48);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->Location = System::Drawing::Point(1158, 577);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(50, 50);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Transparent;
			this->button3->Font = (gcnew System::Drawing::Font(L"新細明體", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button3->Location = System::Drawing::Point(1270, 577);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(50, 50);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Transparent;
			this->button4->Location = System::Drawing::Point(1214, 633);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(50, 50);
			this->button4->TabIndex = 3;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->progressBar3);
			this->panel1->Controls->Add(this->progressBar2);
			this->panel1->Controls->Add(this->progressBar1);
			this->panel1->Location = System::Drawing::Point(4, 569);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(198, 114);
			this->panel1->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(115, 94);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"label3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(115, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"label2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(115, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"label1";
			// 
			// progressBar3
			// 
			this->progressBar3->Location = System::Drawing::Point(9, 84);
			this->progressBar3->Name = L"progressBar3";
			this->progressBar3->Size = System::Drawing::Size(100, 23);
			this->progressBar3->TabIndex = 5;
			// 
			// progressBar2
			// 
			this->progressBar2->Location = System::Drawing::Point(9, 54);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(100, 23);
			this->progressBar2->TabIndex = 5;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(9, 25);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(100, 23);
			this->progressBar1->TabIndex = 5;
			this->progressBar1->Click += gcnew System::EventHandler(this, &Form1::progressBar1_Click);
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(517, 396);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(101, 109);
			this->panel2->TabIndex = 5;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel2_Paint);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(1214, 577);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(50, 50);
			this->button5->TabIndex = 6;
			this->button5->Text = L"button5";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1332, 688);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}

		// 函數用於開始遊戲
		void StartGame() {
			//InitializeGame();
			//RenderGameScreen();
			//GameLoop();
		}

#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		V = -5 * 5;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		   // 将角度增加90度（顺时针旋转90度）
		V = -5 * 5;     // 设置线速度为正值，表示向前运动
		W = 1;
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		   // 将角度减少90度（顺时针旋转90度）
		V = 5 * 5;     // 设置线速度为正值，表示向前运动
		W = -1;
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		V = 5 * 5;
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		V = 0;
		W = 0;
	}
		   void Motion_model(void)
		   {
			   X = X + V * cos(Theta) * dt;
			   Y = Y + V * sin(Theta) * dt;
			   Theta = Theta + W * dt;
		   };


	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		system_counter++;
		Motion_model();
		panel2->Location = Point(X,Y); // 假设面板的名称为panel1
	}
private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}

};
}
