#pragma once

#include "Unordered_Table.h"
#include "OrderedTable.h"
#include "HashTable.h"
#include "AVLTree.h"
#include "HashTableF1.h"

#include <msclr/marshal_cppstd.h>

using namespace std;

namespace lab6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	
	private: 
		UnorderedTable<int, string>* ut;
		PolynomialUTable<int>* put;
		
		UnorderedTableList<int, string>* utL;
		PolynomialUTableList<int>* putL;
		

		OrderedTable<int, string>* ot;
		PolynomialOrdTable<int>* pot;


		AVLTree<int, string>* avlt;
		PolynomialAVLTree<int>* pavlt;

		HashTableF1<int, string>* htf1;
		PolynomialHashTableF1<int>* phtf1;

		HashTable<int, string>* ht;
		PolynomialHashTable<int>* pht;
		
		enum class EditMode
		{
			UTable,
			UTableList,
			OTable,
			AVLT,
			HTableF1,
			HTable
		};

		enum class Type
		{
			String_type,
			Polynomial_type
		};

		EditMode mode;
		Type type;
		Polynomial_::Point* p;
	
		System::Windows::Forms::GroupBox^ groupBox1;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::RadioButton^ unordered_table_btn;
		System::Windows::Forms::RadioButton^ unordered_tableList_btn;
		System::Windows::Forms::RadioButton^ hash_table_btn;
		System::Windows::Forms::RadioButton^ avl_tree_btn;
		System::Windows::Forms::RadioButton^ ordered_table_btn;
		System::Windows::Forms::RadioButton^ hash_table_F1_btn;

		System::Windows::Forms::GroupBox^ groupBox2;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ tooltip_label;
		System::Windows::Forms::TextBox^ value_field;
		System::Windows::Forms::TextBox^ key_field;
		System::Windows::Forms::Button^ insert_button;
		System::Windows::Forms::Button^ delete_button;
		System::Windows::Forms::Label^ warning_msg;
		System::Windows::Forms::Button^ show_button;
	
		System::Windows::Forms::GroupBox^ groupBox3;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ current_point_value_label;
		System::Windows::Forms::TextBox^ x_textBox;
		System::Windows::Forms::TextBox^ y_textBox;
		System::Windows::Forms::TextBox^ z_textBox;	
		System::Windows::Forms::Button^ set_point_button;
	
		System::Windows::Forms::Button^ Calculate_button;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::ListBox^ tableView_listBox;
	
		System::Windows::Forms::GroupBox^ groupBox5;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::RadioButton^ type_polynomial;
		System::Windows::Forms::RadioButton^ type_string;
	    

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;	  
	
	public:
		MyForm(void)
		{
			InitializeComponent();

			ut = new UnorderedTable<int, string>();
			put = new PolynomialUTable<int>();
			
			utL = new UnorderedTableList<int, string>();
			putL = new PolynomialUTableList<int>();
			

			ot = new OrderedTable<int, string>();
			pot = new PolynomialOrdTable<int>();
			
			avlt = new AVLTree<int, string>();
			pavlt = new PolynomialAVLTree<int>();
			
			ht = new HashTable<int, string>();
			pht = new PolynomialHashTable<int>();
			
			htf1 = new HashTableF1<int, string>();
			phtf1 = new PolynomialHashTableF1<int>();
			
			p = new Polynomial_::Point(0, 0, 0);

			mode = EditMode::UTable;
			unordered_table_btn->Checked = true;
			
			type = Type::String_type;
			type_string->Checked = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->unordered_table_btn = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->hash_table_F1_btn = (gcnew System::Windows::Forms::RadioButton());
			this->unordered_tableList_btn = (gcnew System::Windows::Forms::RadioButton());
			this->hash_table_btn = (gcnew System::Windows::Forms::RadioButton());
			this->avl_tree_btn = (gcnew System::Windows::Forms::RadioButton());
			this->ordered_table_btn = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->show_button = (gcnew System::Windows::Forms::Button());
			this->warning_msg = (gcnew System::Windows::Forms::Label());
			this->delete_button = (gcnew System::Windows::Forms::Button());
			this->insert_button = (gcnew System::Windows::Forms::Button());
			this->value_field = (gcnew System::Windows::Forms::TextBox());
			this->Calculate_button = (gcnew System::Windows::Forms::Button());
			this->key_field = (gcnew System::Windows::Forms::TextBox());
			this->tooltip_label = (gcnew System::Windows::Forms::Label());
			this->tableView_listBox = (gcnew System::Windows::Forms::ListBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->current_point_value_label = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->z_textBox = (gcnew System::Windows::Forms::TextBox());
			this->y_textBox = (gcnew System::Windows::Forms::TextBox());
			this->set_point_button = (gcnew System::Windows::Forms::Button());
			this->x_textBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->type_polynomial = (gcnew System::Windows::Forms::RadioButton());
			this->type_string = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->SuspendLayout();
			// 
			// unordered_table_btn
			// 
			this->unordered_table_btn->AutoSize = true;
			this->unordered_table_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->unordered_table_btn->Location = System::Drawing::Point(6, 21);
			this->unordered_table_btn->Name = L"unordered_table_btn";
			this->unordered_table_btn->Size = System::Drawing::Size(126, 20);
			this->unordered_table_btn->TabIndex = 0;
			this->unordered_table_btn->TabStop = true;
			this->unordered_table_btn->Text = L"Unordered table";
			this->unordered_table_btn->UseVisualStyleBackColor = true;
			this->unordered_table_btn->CheckedChanged += gcnew System::EventHandler(this, &MyForm::unordered_table_btn_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->hash_table_F1_btn);
			this->groupBox1->Controls->Add(this->unordered_tableList_btn);
			this->groupBox1->Controls->Add(this->hash_table_btn);
			this->groupBox1->Controls->Add(this->avl_tree_btn);
			this->groupBox1->Controls->Add(this->ordered_table_btn);
			this->groupBox1->Controls->Add(this->unordered_table_btn);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(12, 67);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(244, 161);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Структура данных";
			// 
			// hash_table_F1_btn
			// 
			this->hash_table_F1_btn->AutoSize = true;
			this->hash_table_F1_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->hash_table_F1_btn->Location = System::Drawing::Point(115, 125);
			this->hash_table_F1_btn->Name = L"hash_table_F1_btn";
			this->hash_table_F1_btn->Size = System::Drawing::Size(112, 20);
			this->hash_table_F1_btn->TabIndex = 5;
			this->hash_table_F1_btn->TabStop = true;
			this->hash_table_F1_btn->Text = L"Hash-table F1";
			this->hash_table_F1_btn->UseVisualStyleBackColor = true;
			this->hash_table_F1_btn->CheckedChanged += gcnew System::EventHandler(this, &MyForm::hash_table_F1_btn_CheckedChanged);
			// 
			// unordered_tableList_btn
			// 
			this->unordered_tableList_btn->AutoSize = true;
			this->unordered_tableList_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->unordered_tableList_btn->Location = System::Drawing::Point(6, 47);
			this->unordered_tableList_btn->Name = L"unordered_tableList_btn";
			this->unordered_tableList_btn->Size = System::Drawing::Size(154, 20);
			this->unordered_tableList_btn->TabIndex = 4;
			this->unordered_tableList_btn->TabStop = true;
			this->unordered_tableList_btn->Text = L"Unordered table(List)";
			this->unordered_tableList_btn->UseVisualStyleBackColor = true;
			this->unordered_tableList_btn->CheckedChanged += gcnew System::EventHandler(this, &MyForm::unordered_tableList_btn_CheckedChanged);
			// 
			// hash_table_btn
			// 
			this->hash_table_btn->AutoSize = true;
			this->hash_table_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->hash_table_btn->Location = System::Drawing::Point(6, 125);
			this->hash_table_btn->Name = L"hash_table_btn";
			this->hash_table_btn->Size = System::Drawing::Size(94, 20);
			this->hash_table_btn->TabIndex = 3;
			this->hash_table_btn->TabStop = true;
			this->hash_table_btn->Text = L"Hash-table";
			this->hash_table_btn->UseVisualStyleBackColor = true;
			this->hash_table_btn->CheckedChanged += gcnew System::EventHandler(this, &MyForm::hash_table_btn_CheckedChanged);
			// 
			// avl_tree_btn
			// 
			this->avl_tree_btn->AutoSize = true;
			this->avl_tree_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->avl_tree_btn->Location = System::Drawing::Point(6, 99);
			this->avl_tree_btn->Name = L"avl_tree_btn";
			this->avl_tree_btn->Size = System::Drawing::Size(80, 20);
			this->avl_tree_btn->TabIndex = 2;
			this->avl_tree_btn->TabStop = true;
			this->avl_tree_btn->Text = L"AVL-tree";
			this->avl_tree_btn->UseVisualStyleBackColor = true;
			this->avl_tree_btn->CheckedChanged += gcnew System::EventHandler(this, &MyForm::avl_tree_btn_CheckedChanged);
			// 
			// ordered_table_btn
			// 
			this->ordered_table_btn->AutoSize = true;
			this->ordered_table_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->ordered_table_btn->Location = System::Drawing::Point(6, 73);
			this->ordered_table_btn->Name = L"ordered_table_btn";
			this->ordered_table_btn->Size = System::Drawing::Size(111, 20);
			this->ordered_table_btn->TabIndex = 1;
			this->ordered_table_btn->TabStop = true;
			this->ordered_table_btn->Text = L"Ordered table";
			this->ordered_table_btn->UseVisualStyleBackColor = true;
			this->ordered_table_btn->CheckedChanged += gcnew System::EventHandler(this, &MyForm::ordered_table_btn_CheckedChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->show_button);
			this->groupBox2->Controls->Add(this->warning_msg);
			this->groupBox2->Controls->Add(this->delete_button);
			this->groupBox2->Controls->Add(this->insert_button);
			this->groupBox2->Controls->Add(this->value_field);
			this->groupBox2->Controls->Add(this->Calculate_button);
			this->groupBox2->Controls->Add(this->key_field);
			this->groupBox2->Controls->Add(this->tooltip_label);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(12, 234);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(244, 249);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Редактирование";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::Control;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(6, 201);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(125, 16);
			this->label5->TabIndex = 8;
			this->label5->Text = L"*для полиномов";
			// 
			// show_button
			// 
			this->show_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->show_button->Location = System::Drawing::Point(6, 153);
			this->show_button->Name = L"show_button";
			this->show_button->Size = System::Drawing::Size(232, 23);
			this->show_button->TabIndex = 7;
			this->show_button->Text = L"Показать таблицу";
			this->show_button->UseVisualStyleBackColor = true;
			this->show_button->Click += gcnew System::EventHandler(this, &MyForm::Show_Button_Click);
			// 
			// warning_msg
			// 
			this->warning_msg->AutoSize = true;
			this->warning_msg->BackColor = System::Drawing::SystemColors::Control;
			this->warning_msg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->warning_msg->ForeColor = System::Drawing::Color::Red;
			this->warning_msg->Location = System::Drawing::Point(6, 134);
			this->warning_msg->Name = L"warning_msg";
			this->warning_msg->Size = System::Drawing::Size(136, 16);
			this->warning_msg->TabIndex = 6;
			this->warning_msg->Text = L"Warning_message";
			// 
			// delete_button
			// 
			this->delete_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->delete_button->Location = System::Drawing::Point(6, 108);
			this->delete_button->Name = L"delete_button";
			this->delete_button->Size = System::Drawing::Size(232, 23);
			this->delete_button->TabIndex = 5;
			this->delete_button->Text = L"Удалить";
			this->delete_button->UseVisualStyleBackColor = true;
			this->delete_button->Click += gcnew System::EventHandler(this, &MyForm::delete_button_Click);
			// 
			// insert_button
			// 
			this->insert_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->insert_button->Location = System::Drawing::Point(6, 79);
			this->insert_button->Name = L"insert_button";
			this->insert_button->Size = System::Drawing::Size(232, 23);
			this->insert_button->TabIndex = 4;
			this->insert_button->Text = L"Вставить";
			this->insert_button->UseVisualStyleBackColor = true;
			this->insert_button->Click += gcnew System::EventHandler(this, &MyForm::Insert_Click);
			// 
			// value_field
			// 
			this->value_field->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->value_field->Location = System::Drawing::Point(56, 51);
			this->value_field->Name = L"value_field";
			this->value_field->Size = System::Drawing::Size(182, 22);
			this->value_field->TabIndex = 3;
			// 
			// Calculate_button
			// 
			this->Calculate_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Calculate_button->Location = System::Drawing::Point(6, 220);
			this->Calculate_button->Name = L"Calculate_button";
			this->Calculate_button->Size = System::Drawing::Size(232, 23);
			this->Calculate_button->TabIndex = 9;
			this->Calculate_button->Text = L"Вычислить полиномы";
			this->Calculate_button->UseVisualStyleBackColor = true;
			this->Calculate_button->Click += gcnew System::EventHandler(this, &MyForm::Calculate_button_Click);
			// 
			// key_field
			// 
			this->key_field->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->key_field->Location = System::Drawing::Point(6, 51);
			this->key_field->Name = L"key_field";
			this->key_field->Size = System::Drawing::Size(44, 22);
			this->key_field->TabIndex = 2;
			// 
			// tooltip_label
			// 
			this->tooltip_label->AutoSize = true;
			this->tooltip_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tooltip_label->Location = System::Drawing::Point(6, 32);
			this->tooltip_label->Name = L"tooltip_label";
			this->tooltip_label->Size = System::Drawing::Size(203, 18);
			this->tooltip_label->TabIndex = 0;
			this->tooltip_label->Text = L"Запись (ключ, значение)";
			// 
			// tableView_listBox
			// 
			this->tableView_listBox->FormattingEnabled = true;
			this->tableView_listBox->ItemHeight = 16;
			this->tableView_listBox->Location = System::Drawing::Point(262, 19);
			this->tableView_listBox->Name = L"tableView_listBox";
			this->tableView_listBox->Size = System::Drawing::Size(675, 596);
			this->tableView_listBox->TabIndex = 3;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->current_point_value_label);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Controls->Add(this->z_textBox);
			this->groupBox3->Controls->Add(this->y_textBox);
			this->groupBox3->Controls->Add(this->set_point_button);
			this->groupBox3->Controls->Add(this->x_textBox);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox3->Location = System::Drawing::Point(12, 489);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(244, 129);
			this->groupBox3->TabIndex = 8;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Точка";
			// 
			// current_point_value_label
			// 
			this->current_point_value_label->AutoSize = true;
			this->current_point_value_label->BackColor = System::Drawing::SystemColors::Control;
			this->current_point_value_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->current_point_value_label->ForeColor = System::Drawing::Color::Black;
			this->current_point_value_label->Location = System::Drawing::Point(23, 32);
			this->current_point_value_label->Name = L"current_point_value_label";
			this->current_point_value_label->Size = System::Drawing::Size(161, 18);
			this->current_point_value_label->TabIndex = 11;
			this->current_point_value_label->Text = L"Текущая точка: (0,0,0)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::Control;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(151, 69);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(20, 16);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Z:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::Control;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(76, 69);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(21, 16);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Y:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Control;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(6, 69);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 16);
			this->label1->TabIndex = 8;
			this->label1->Text = L"X:";
			// 
			// z_textBox
			// 
			this->z_textBox->Location = System::Drawing::Point(176, 66);
			this->z_textBox->Name = L"z_textBox";
			this->z_textBox->Size = System::Drawing::Size(44, 24);
			this->z_textBox->TabIndex = 4;
			// 
			// y_textBox
			// 
			this->y_textBox->Location = System::Drawing::Point(101, 66);
			this->y_textBox->Name = L"y_textBox";
			this->y_textBox->Size = System::Drawing::Size(44, 24);
			this->y_textBox->TabIndex = 3;
			// 
			// set_point_button
			// 
			this->set_point_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->set_point_button->Location = System::Drawing::Point(6, 94);
			this->set_point_button->Name = L"set_point_button";
			this->set_point_button->Size = System::Drawing::Size(232, 23);
			this->set_point_button->TabIndex = 5;
			this->set_point_button->Text = L"Установить";
			this->set_point_button->UseVisualStyleBackColor = true;
			this->set_point_button->Click += gcnew System::EventHandler(this, &MyForm::set_point_button_Click);
			// 
			// x_textBox
			// 
			this->x_textBox->Location = System::Drawing::Point(26, 66);
			this->x_textBox->Name = L"x_textBox";
			this->x_textBox->Size = System::Drawing::Size(44, 24);
			this->x_textBox->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 18);
			this->label2->TabIndex = 0;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->type_polynomial);
			this->groupBox5->Controls->Add(this->type_string);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox5->Location = System::Drawing::Point(12, 12);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(244, 49);
			this->groupBox5->TabIndex = 13;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Тип данных";
			// 
			// type_polynomial
			// 
			this->type_polynomial->AutoSize = true;
			this->type_polynomial->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->type_polynomial->Location = System::Drawing::Point(72, 21);
			this->type_polynomial->Name = L"type_polynomial";
			this->type_polynomial->Size = System::Drawing::Size(94, 20);
			this->type_polynomial->TabIndex = 7;
			this->type_polynomial->TabStop = true;
			this->type_polynomial->Text = L"polynomial";
			this->type_polynomial->UseVisualStyleBackColor = true;
			this->type_polynomial->CheckedChanged += gcnew System::EventHandler(this, &MyForm::type_polynomial_CheckedChanged);
			// 
			// type_string
			// 
			this->type_string->AutoSize = true;
			this->type_string->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->type_string->Location = System::Drawing::Point(6, 21);
			this->type_string->Name = L"type_string";
			this->type_string->Size = System::Drawing::Size(60, 20);
			this->type_string->TabIndex = 6;
			this->type_string->TabStop = true;
			this->type_string->Text = L"string";
			this->type_string->UseVisualStyleBackColor = true;
			this->type_string->CheckedChanged += gcnew System::EventHandler(this, &MyForm::type_string_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(949, 641);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->tableView_listBox);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: void SetMode(EditMode m)
	{
		mode = m;
		tableView_listBox->Items->Clear();
	}
	
	private: System::Void type_string_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		type = Type::String_type;
		tableView_listBox->Items->Clear();
	}
	private: System::Void type_polynomial_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		type = Type::Polynomial_type;
		tableView_listBox->Items->Clear();
	}
	private: System::Void unordered_table_btn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		SetMode(EditMode::UTable);
	}
	private: System::Void unordered_tableList_btn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		SetMode(EditMode::UTableList);
	}	
	private: System::Void ordered_table_btn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		SetMode(EditMode::OTable);
	}
	private: System::Void avl_tree_btn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		SetMode(EditMode::AVLT);
	}
	private: System::Void hash_table_btn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		SetMode(EditMode::HTable);
	}
	private: System::Void hash_table_F1_btn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		SetMode(EditMode::HTableF1);
	}
	private: System::Void delete_button_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ str_key = key_field->Text;
		int int_key;
		switch (type)
		{
		case Type::String_type:
			if (Int32::TryParse(str_key, int_key)) {
				switch (mode)
				{
				case EditMode::UTable:
					ut->Delete(int_key);
					break;
				case EditMode::UTableList:
					utL->Delete(int_key);
					break;
				case EditMode::OTable:
					ot->Delete(int_key);
					break;
				case EditMode::AVLT:
					avlt->Delete(int_key);
					break;
				case EditMode::HTable:
					ht->Delete(int_key);
					break;
				case EditMode::HTableF1:
					htf1->Delete(int_key);
					break;
				default:
					break;
				}
				warning_msg->ForeColor = Color::Green;
				warning_msg->Text = "Done";
			}
			else
			{
				warning_msg->ForeColor = Color::Red;
				warning_msg->Text = "incorrect key";
			}
			break;
		case Type::Polynomial_type:
			if (Int32::TryParse(str_key, int_key)) {
				switch (mode)
				{
				case EditMode::UTable:
					put->Delete(int_key);
					break;
				case EditMode::UTableList:
					putL->Delete(int_key);
					break;
				case EditMode::OTable:
					pot->Delete(int_key);
					break;
				case EditMode::AVLT:
					pavlt->Delete(int_key);
					break;
				case EditMode::HTable:
					pht->Delete(int_key);
					break;
				case EditMode::HTableF1:
					phtf1->Delete(int_key);
					break;
				default:
					break;
				}
				warning_msg->ForeColor = Color::Green;
				warning_msg->Text = "Done";
			}
			else
			{
				warning_msg->ForeColor = Color::Red;
				warning_msg->Text = "incorrect key";
			}
			break;
		default:
			break;
		}
	}
	private: System::Void Insert_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ str_key = key_field->Text;
		string value = msclr::interop::marshal_as<string>(value_field->Text);
		int int_key;
		
		switch (type)
		{
		case Type::String_type:
			if (Int32::TryParse(str_key, int_key)) {
				switch (mode)
				{
				case EditMode::UTable:
					ut->Insert(int_key, value);
					break;
				case EditMode::UTableList:
					utL->Insert(int_key, value);
					break;
				case EditMode::OTable:
					ot->Insert(int_key, value);
					break;
				case EditMode::AVLT:
					avlt->Insert(int_key, value);
					break;
				case EditMode::HTable:
					ht->Insert(int_key, value);
					break;
				case EditMode::HTableF1:
					htf1->Insert(int_key, value);
					break;
				default:
					break;
				}
				warning_msg->ForeColor = Color::Green;
				warning_msg->Text = "Done";
			}
			else 
			{
				warning_msg->ForeColor = Color::Red;
				warning_msg->Text = "incorrect key";
			}
			break;
		case Type::Polynomial_type:
			// Проверка на корректность ввода
			if (Int32::TryParse(str_key, int_key)) {
				String^ text_polynom = value_field->Text;
				Polynomial_::Polynomial polynomial(value);
				switch (mode)
				{
				case EditMode::UTable:
					put->Insert(int_key, Polynomial(value));
					break;
				case EditMode::UTableList:
					putL->Insert(int_key, Polynomial(value));
					break;
				case EditMode::OTable:
					pot->Insert(int_key, Polynomial(value));
					break;
				case EditMode::AVLT:
					pavlt->Insert(int_key, Polynomial(value));
					break;
				case EditMode::HTable:
					pht->Insert(int_key, Polynomial(value));
					break;
				case EditMode::HTableF1:
					phtf1->Insert(int_key, Polynomial(value));
					break;
				default:
					break;
				}
				warning_msg->ForeColor = Color::Green;
				warning_msg->Text = "Done";
			}
			else
			{
				warning_msg->ForeColor = Color::Red;
				warning_msg->Text = "incorrect key";
			}
			break;
		default:
			break;
		}
	}

	private: System::Void Show_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		tableView_listBox->Items->Clear();
		switch (type)
		{
		case Type::String_type:
			switch (mode)
			{
			case EditMode::UTable:
				for (int i = 0; i < ut->GetSize(); i++)
				{
					tableView_listBox->Items->Add(msclr::interop::marshal_as<String^>(ut->GetRec(i)));
				}
				break;
			case EditMode::UTableList:
				for (int i = 0; i < utL->GetSize(); i++)
				{
					tableView_listBox->Items->Add(msclr::interop::marshal_as<String^>(utL->GetRec(i)));
				}
				break;
			case EditMode::OTable:
				for (int i = 0; i < ot->GetSize(); i++)
				{
					tableView_listBox->Items->Add(msclr::interop::marshal_as<String^>(ot->GetRec(i)));
				}
				break;
			case EditMode::AVLT:
				avlt->Print(tableView_listBox);
				break;
			case EditMode::HTable:
				for (int i = 0; i < ht->GetCapacity(); i++)
				{
					tableView_listBox->Items->Add(msclr::interop::marshal_as<String^>(ht->GetRec(i)));
				}
				break;
			case EditMode::HTableF1:
				for (int i = 0; i < htf1->GetCapacity(); i++)
				{
					tableView_listBox->Items->Add(msclr::interop::marshal_as<String^>(htf1->GetRec(i)));
				}
				break;
			default:
				break;
			}
			break;
		case Type::Polynomial_type:
			switch (mode)
			{
			case EditMode::UTable:
				for (int i = 0; i < put->GetSize(); i++)
				{
					tableView_listBox->Items->Add(msclr::interop::marshal_as<String^>(put->GetRec(i)));
				}
				break;
			case EditMode::UTableList:
				for (int i = 0; i < putL->GetSize(); i++)
				{
					tableView_listBox->Items->Add(msclr::interop::marshal_as<String^>(putL->GetRec(i)));
				}
				break;
			case EditMode::OTable:
				for (int i = 0; i < pot->GetSize(); i++)
				{
					tableView_listBox->Items->Add(msclr::interop::marshal_as<String^>(pot->GetRec(i)));
				}
				break;
			case EditMode::AVLT:
				pavlt->Print(tableView_listBox);
				break;
			case EditMode::HTable:
				for (int i = 0; i < pht->GetCapacity(); i++)
				{
					tableView_listBox->Items->Add(msclr::interop::marshal_as<String^>(pht->GetRec(i)));
				}
				break;
			case EditMode::HTableF1:
				for (int i = 0; i < phtf1->GetCapacity(); i++)
				{
					tableView_listBox->Items->Add(msclr::interop::marshal_as<String^>(phtf1->GetRec(i)));
				}
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}

	private: System::Void set_point_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Int32::TryParse(x_textBox->Text, p->x) &&
			Int32::TryParse(y_textBox->Text, p->y) &&
			Int32::TryParse(z_textBox->Text, p->z))
		{
			warning_msg->ForeColor = Color::Black;
			current_point_value_label->Text = "Текущая точка: (" + p->x + ", " + p->y + ", " + p->z + ")";
		}
		else
		{
			warning_msg->ForeColor = Color::Red;
			current_point_value_label->Text = "Incorrect values";
		}
	}

	private: System::Void Calculate_button_Click(System::Object^ sender, System::EventArgs^ e) {
		switch (mode)
		{
		case EditMode::UTable:
			put->Calculate(*p);
			break;
		case EditMode::UTableList:
			putL->Calculate(*p);
			break;
		case EditMode::OTable:
			pot->Calculate(*p);
			break;
		case EditMode::AVLT:
			pavlt->Calculate(*p);
			break;
		case EditMode::HTable:
			pht->Calculate(*p);
			break;
		case EditMode::HTableF1:
			phtf1->Calculate(*p);
			break;
		default:
			break;
		}
	}
};
}
