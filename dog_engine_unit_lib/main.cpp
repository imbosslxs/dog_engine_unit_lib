#include "main.h"
int deu_main(int argc,char **argv) {
	auto &d = director::get_instance();
	auto &de = d.get_dog_engine();

	de.set_window_size(100,30);

	de.set_title("Dog Engine Unit Demo");

	auto sc = scene::create();
	d.begin_scene(sc);

	auto layer1 = layer::create();
	sc->add_child(layer1);
	layer1->set_color(DOG_COLOR_WHITE);

	fstream f_in("in.txt",ios::in);
	string s = json_object_type::read_file_all(f_in);
	f_in.close();
	auto bc = bitchar::create(bitchar_type(s),{31,3});
	layer1->add_child(bc);

	auto button1 = button::create(
								{43,12},
								bitchar_type::create_from_string(" start ",true),
								bitchar_type::create_from_string(">start<",true),
								bitchar_type::create_from_string("|start|",true),
								[&]()->bool{
									//msg_box("I'm a button1 !");
									return true;
								});
	layer1->add_child(button1);

	button1 = button::create(
								{42,14},
								bitchar_type::create_from_string(" options ",true),
								bitchar_type::create_from_string(">options<",true),
								bitchar_type::create_from_string("|options|",true),
								[&]()->bool{
									//msg_box("I'm a button1 !");
									return true;
								});
	layer1->add_child(button1);

	button1 = button::create(
								{43,16},
								bitchar_type::create_from_string(" about ",true),
								bitchar_type::create_from_string(">about<",true),
								bitchar_type::create_from_string("|about|",true),
								[&]()->bool{
									//msg_box("I'm a button1 !");
									return true;
								});
	layer1->add_child(button1);

	button1 = button::create(
								{43,18},
								bitchar_type::create_from_string(" quit ",true),
								bitchar_type::create_from_string(">quit<",true),
								bitchar_type::create_from_string("|quit|",true),
								[&]()->bool{
									//msg_box("I'm a button1 !");
									d.quit();
									return true;
								});
	layer1->add_child(button1);


	button1 = button::create(
								{0,de.H-1},
								bitchar_type::create_from_string(" L ",true),
								bitchar_type::create_from_string(">L<",true),
								bitchar_type::create_from_string("|L|",true),
								[&]()->bool{
									//msg_box("I'm a button1 !");
									return true;
								});
	layer1->add_child(button1);

	button1 = button::create(
								{de.W-9,de.H-1},
								bitchar_type::create_from_string(" Log Out ",true),
								bitchar_type::create_from_string(">Log Out<",true),
								bitchar_type::create_from_string("|Log Out|",true),
								[&]()->bool{
									//msg_box("I'm a button1 !");
									return true;
								});
	layer1->add_child(button1);

	auto cs = color_selector::create({5,10},1);
	layer1->add_child(cs);

	auto editor1= editor::create({5,15},{20,1},de.get_title());
	layer1->add_child(editor1);
	auto &e1 = *editor1;
	editor1->set_on_text_change_call_func([&](){
		de.set_title(e1.get_text());
	});

	auto lv1 = listviewer::create({55,17},{29,6});
	layer1->add_child(lv1);
	lv1->set_color(DOG_COLOR_YELLOW);

	auto lv_b1 = button::create(
								{de.W-9,de.H-1},
								bitchar_type::create_from_string(" Button1 ",true),
								bitchar_type::create_from_string(">Button1<",true),
								bitchar_type::create_from_string("|Button1|",true),
								[&]()->bool{
									msg_box("I'm a button1 !");
									return true;
								});
	lv1->add_contain(lv_b1,"b1");

	lv_b1 = button::create(
								{de.W-9,de.H-1},
								bitchar_type::create_from_string(" Button2 ",true),
								bitchar_type::create_from_string(">Button2<",true),
								bitchar_type::create_from_string("|Button2|",true),
								[&]()->bool{
									msg_box("I'm a button1 !");
									return true;
								});
	lv1->add_contain(lv_b1,"b1");

	lv_b1 = button::create(
								{de.W-9,de.H-1},
								bitchar_type::create_from_string(" Button3 ",true),
								bitchar_type::create_from_string(">Button3<",true),
								bitchar_type::create_from_string("|Button3|",true),
								[&]()->bool{
									msg_box("I'm a button2 !");
									return true;
								});
	lv1->add_contain(lv_b1,"b2");

	lv_b1 = button::create(
								{de.W-9,de.H-1},
								bitchar_type::create_from_string(" Button4 ",true),
								bitchar_type::create_from_string(">Button4<",true),
								bitchar_type::create_from_string("|Button4|",true),
								[&]()->bool{
									msg_box("I'm a button3 !");
									return true;
								});
	lv1->add_contain(lv_b1,"b3");

	lv_b1 = button::create(
								{de.W-9,de.H-1},
								bitchar_type::create_from_string(" Button5 ",true),
								bitchar_type::create_from_string(">Button5<",true),
								bitchar_type::create_from_string("|Button5|",true),
								[&]()->bool{
									msg_box("I'm a button4 !");
									return true;
								});
	lv1->add_contain(lv_b1,"b4");

	lv_b1 = button::create(
								{de.W-9,de.H-1},
								bitchar_type::create_from_string(" Button6 ",true),
								bitchar_type::create_from_string(">Button6<",true),
								bitchar_type::create_from_string("|Button6|",true),
								[&]()->bool{
									msg_box("I'm a button5 !");
									return true;
								});
	lv1->add_contain(lv_b1,"b5");

	auto &re_layer1 = *layer1;
	auto button10 = button::create(
								{5,20},
								bitchar_type::create_from_string(" MSGBAR ",true),
								bitchar_type::create_from_string(">MSGBAR<",true),
								bitchar_type::create_from_string("|MSGBAR|",true),
								[&]()->bool{
									auto mbc1 = bitchar_type::create_from_string("\n\nDo you know what have you done just now?\nyou make it!\nYeah!!!\n\n",true);
									mbc1.set_color(DOG_COLOR_WHITE);
									mbc1.set_color(DOG_COLOR_BLACK,false);	
									auto mbar1 = msgbar::create(mbc1);
									re_layer1.add_child(mbar1,"mbar1");
									mbar1->set_color(DOG_COLOR_BLACK);
									d.add_task(3000,[&](){
										re_layer1.remove_child_by_key("mbar1");
									},1);
									return true;
								});
	layer1->add_child(button10);

	auto rc1 = rate_controller::create({5,26},1);
	layer1->add_child(rc1);
	rc1->set_on_value_change_call_func([&](int v,rate_controller &rc){
		msg_box(string("v:") + v);
	});
	return 0;
}