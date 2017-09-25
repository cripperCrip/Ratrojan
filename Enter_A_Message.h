#pragma once

namespace Trojan2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Enter_A_Message
	/// </summary>
	public ref class Enter_A_Message : public System::Windows::Forms::Form
	{
	public:
		Enter_A_Message(void)
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
		~Enter_A_Message()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::TextBox^  MessageBox;
	protected: 


	private: System::Windows::Forms::Button^  CancelButtom;
	private: System::Windows::Forms::Button^  OkButtom;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->MessageBox = (gcnew System::Windows::Forms::TextBox());
			this->CancelButtom = (gcnew System::Windows::Forms::Button());
			this->OkButtom = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(334, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Introduce el mensaje que quieres que se muestre:";
			this->label1->Click += gcnew System::EventHandler(this, &Enter_A_Message::label1_Click);
			// 
			// MessageBox
			// 
			this->MessageBox->Location = System::Drawing::Point(12, 42);
			this->MessageBox->Name = L"MessageBox";
			this->MessageBox->Size = System::Drawing::Size(534, 22);
			this->MessageBox->TabIndex = 1;
			this->MessageBox->TextChanged += gcnew System::EventHandler(this, &Enter_A_Message::MessageBox_TextChanged);
			// 
			// CancelButtom
			// 
			this->CancelButtom->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelButtom->Location = System::Drawing::Point(439, 86);
			this->CancelButtom->Name = L"CancelButtom";
			this->CancelButtom->Size = System::Drawing::Size(109, 36);
			this->CancelButtom->TabIndex = 3;
			this->CancelButtom->Text = L"Cancelar";
			this->CancelButtom->UseVisualStyleBackColor = true;
			// 
			// OkButtom
			// 
			this->OkButtom->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->OkButtom->Location = System::Drawing::Point(324, 86);
			this->OkButtom->Name = L"OkButtom";
			this->OkButtom->Size = System::Drawing::Size(109, 36);
			this->OkButtom->TabIndex = 4;
			this->OkButtom->Text = L"Aceptar";
			this->OkButtom->UseVisualStyleBackColor = true;
			this->OkButtom->Click += gcnew System::EventHandler(this, &Enter_A_Message::OkButtom_Click);
			// 
			// Enter_A_Message
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(571, 134);
			this->ControlBox = false;
			this->Controls->Add(this->OkButtom);
			this->Controls->Add(this->CancelButtom);
			this->Controls->Add(this->MessageBox);
			this->Controls->Add(this->label1);
			this->Name = L"Enter_A_Message";
			this->Text = L"Mensaje";
			this->Load += gcnew System::EventHandler(this, &Enter_A_Message::Enter_A_Message_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) 
		{
		}
private: System::Void Enter_A_Message_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
		private: System::Void OkButtom_Click(System::Object^  sender, System::EventArgs^  e) 
		{

		}
private: System::Void MessageBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
