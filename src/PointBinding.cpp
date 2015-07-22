#include "Point.h"

#include "PointBinding.h"

NAN_METHOD(newPoint) {
	NanScope();

	Point* obj = new Point();
	obj->Wrap(args.This());

	NanReturnValue(args.This());
}

NAN_METHOD(PointMove) {
	NanScope();
	if(args.Length() < 2) {
		printf("invalid arguments for move.\n");
		return;
	}
	int32_t x = args[0]->Int32Value();
	int32_t y = args[1]->Int32Value();

	Point* obj = ObjectWrap::Unwrap<Point>(args.This());
	int retVal =  obj->move(x, y);
	NanReturnValue(NanNew<Int32>(retVal));
}

NAN_METHOD(PointAdd) {
	NanScope();
	if(args.Length() < 2) {
		printf("invalid arguments for add.\n");
		return;
	}
	int32_t x = args[0]->Int32Value();
	int32_t y = args[1]->Int32Value();

	Point* obj = ObjectWrap::Unwrap<Point>(args.This());
	string retVal =  obj->add(x, y);
	NanReturnValue(NanNew<String>(retVal.c_str()));
}

NAN_METHOD(PointCopy) {
	NanScope();
	if(args.Length() < 1) {
		printf("invalid arguments for copy.\n");
		return;
	}
	Local<Object> otherObj = args[0]->ToObject();
	Point* other = ObjectWrap::Unwrap<Point>(otherObj);

	Point* obj = ObjectWrap::Unwrap<Point>(args.This());
	bool retVal =  obj->copy(other);
	NanReturnValue(NanNew<Boolean>(retVal));
}

NAN_GETTER(PointGetX) {
	NanScope();
	Point* obj = ObjectWrap::Unwrap<Point>(args.This());
	NanReturnValue(NanNew<Int32>(obj->getX()));
}

NAN_SETTER(PointSetX) {
	NanScope();
	Point* obj = ObjectWrap::Unwrap<Point>(args.This());
	if (value->IsInt32()) {
		int32_t nativeValue = value->Int32Value();
		obj->setX(nativeValue);
	}else{
		printf("invalid data type for Point.x\n");
	}
}

NAN_GETTER(PointGetY) {
	NanScope();
	Point* obj = ObjectWrap::Unwrap<Point>(args.This());
	NanReturnValue(NanNew<Int32>(obj->getY()));
}

NAN_SETTER(PointSetY) {
	NanScope();
	Point* obj = ObjectWrap::Unwrap<Point>(args.This());
	if (value->IsInt32()) {
		int32_t nativeValue = value->Int32Value();
		obj->setY(nativeValue);
	}else{
		printf("invalid data type for Point.y\n");
	}
}

NAN_GETTER(PointGetMagic) {
	NanScope();
	Point* obj = ObjectWrap::Unwrap<Point>(args.This());
	NanReturnValue(NanNew<String>(obj->getMagic()));
}

NAN_SETTER(PointSetMagic) {
	NanScope();
	Point* obj = ObjectWrap::Unwrap<Point>(args.This());
	if (value->IsString()) {
		v8::String::Utf8Value nativeValue(value);
		obj->setMagic(*nativeValue);
	}else{
		printf("invalid data type for Point.magic\n");
	}
}



static Persistent<FunctionTemplate> constructor;
void PointInitBinding(Handle<Object>& target) {
	NanScope();
	Local<FunctionTemplate> ctor = NanNew<FunctionTemplate>(newPoint);
	NanAssignPersistent(constructor, ctor);
	ctor->InstanceTemplate()->SetInternalFieldCount(1);
	ctor->SetClassName(NanNew("Point"));
	Local<ObjectTemplate> proto = ctor->PrototypeTemplate();
	
	proto->SetAccessor(NanNew("x"), PointGetX, PointSetX);
	proto->SetAccessor(NanNew("y"), PointGetY, PointSetY);
	proto->SetAccessor(NanNew("magic"), PointGetMagic, PointSetMagic);

	NAN_SET_PROTOTYPE_METHOD(ctor, "move", PointMove);
	NAN_SET_PROTOTYPE_METHOD(ctor, "add", PointAdd);
	NAN_SET_PROTOTYPE_METHOD(ctor, "copy", PointCopy);

	NanSetTemplate(proto, "DEFAULT_NAME", NanNew<String>(POINT_DEFAULT_NAME));
	NanSetTemplate(proto, "DEFAULT_X", NanNew<Int32>(POINT_DEFAULT_X));
	NanSetTemplate(proto, "DEFAULT_Y", NanNew<Int32>(POINT_DEFAULT_Y));

}
