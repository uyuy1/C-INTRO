#ifndef SICT_Enrollment_H_
#define SICT_Enrollment_H_

namespace sict{

	class Enrollment{
	private:
		char name_[31];
		char code_[11];
		int year_;
		int semester_;
		int slot_;
		bool enrolled_;
	public:

		Enrollment(const char* name, const char* code, int year, int slot, int semester, bool enrolled = false);
		Enrollment();
		void display(bool nameOnly = false)const;
		bool isValid()const;
		void setEmpty();
		bool isEnrolled() const;
		void set(const char* name, const char* code, int year, int
		time, int semester, bool enrolled = false);
		bool hasConflict(const Enrollment &other) const;
	
	};
}

#endif
