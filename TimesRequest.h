#pragma once

namespace Trojan2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TimesRequest
	/// </summary>
	public ref class TimesRequest : public System::Windows::Forms::Form
	{
	public:
		TimesRequest(void)
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
		~TimesRequest()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::NumericUpDown^  Numeric;
	protected: 

	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  OkButtom;
	private: System::Windows::Forms::Button^  CancelButtom;

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
			this->Numeric = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->OkButtom = (gcnew System::Windows::Forms::Button());
			this->CancelButtom = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Numeric))->BeginInit();
			this->SuspendLayout();
			// 
			// Numeric
			// 
			this->Numeric->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Numeric->Location = System::Drawing::Point(12, 57);
			this->Numeric->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->Numeric->Name = L"Numeric";
			this->Numeric->Size = System::Drawing::Size(87, 24);
			this->Numeric->TabIndex = 0;
			this->Numeric->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->Numeric->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->Numeric->ValueChanged += gcnew System::EventHandler(this, &TimesRequest::Numeric_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(187, 18);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Número de Notepad a abrir";
			this->label1->Click += gcnew System::EventHandler(this, &TimesRequest::label1_Click);
			// 
			// OkButtom
			// 
			this->OkButtom->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->OkButtom->Location = System::Drawing::Point(46, 117);
			this->OkButtom->Name = L"OkButtom";
			this->OkButtom->Size = System::Drawing::Size(109, 36);
			this->OkButtom->TabIndex = 5;
			this->OkButtom->Text = L"Aceptar";
			this->OkButtom->UseVisualStyleBackColor = true;
			// 
			// CancelButtom
			// 
			this->CancelButtom->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelButtom->Location = System::Drawing::Point(161, 117);
			this->CancelButtom->Name = L"CancelButtom";
			this->CancelButtom->Size = System::Drawing::Size(109, 36);
			this->CancelButtom->TabIndex = 6;
			this->CancelButtom->Text = L"Cancelar";
			this->CancelButtom->UseVisualStyleBackColor = true;
			// 
			// TimesRequest
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 159);
			this->ControlBox = false;
			this->Controls->Add(this->CancelButtom);
			this->Controls->Add(this->OkButtom);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Numeric);
			this->Name = L"TimesRequest";
			this->Text = L"Número de NotePad a abrir";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Numeric))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void Numeric_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}
