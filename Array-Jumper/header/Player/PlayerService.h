#pragma 
namespace Player {
	class PlayerController;
	class PlayerService
	{
	private:
		PlayerController* playe_controller;

		void destroy();

	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();
	};
}
