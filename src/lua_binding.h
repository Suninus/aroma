#pragma once

#include "common.h"

namespace aroma {
	class Bindable {
		public:
			virtual const char* module_name() = 0;
			virtual void bind_all(lua_State *l) = 0;
	};

	class LuaBinding {
		protected:
			lua_State* l;
			void preload_library(const char* name);

		public:
			LuaBinding();
			lua_State* lua();

			virtual void bind_module(Bindable *b);
			virtual bool bind_all(); // set up the lua env

			bool is_type(int i, const char* type);

			bool load_and_run(void* buffer, size_t buff_len, const char* name);
			void push_self();
	};
}
