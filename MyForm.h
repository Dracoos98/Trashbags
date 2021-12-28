#pragma once
#include "Controladora.h";
namespace Basura {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			objcontroladora = new Controladora();
			bmpbasuraVerde = gcnew Bitmap("BV.png");
			bmpbasuraRoja = gcnew Bitmap("BR.png");
			bmpbasuraAzul = gcnew Bitmap("BA.png");
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete bmpbasuraVerde,objcontroladora,bmpbasuraRoja,bmpbasuraAzul;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Bitmap^ bmpbasuraVerde;
		Bitmap^ bmpbasuraRoja;
		Bitmap^ bmpbasuraAzul;
		Controladora* objcontroladora;
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(985, 562);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = espacio->Allocate(g, ClientRectangle);
		bf->Graphics->Clear(Color::White);
		objcontroladora->Insertar_Basura();
		objcontroladora->Dibujar_Basura1(bf->Graphics, bmpbasuraVerde);
		objcontroladora->Dibujar_Basura2(bf->Graphics, bmpbasuraRoja);
		objcontroladora->Dibujar_Basura3(bf->Graphics, bmpbasuraAzul);
		bf->Render(g);
		delete bf, g, espacio;
	}
	};
}
